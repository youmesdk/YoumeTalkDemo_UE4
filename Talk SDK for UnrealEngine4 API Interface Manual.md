# Talk SDK for UnrealEngine4 API Interface Manual

## Introduction of related asynchronous / synchronous processing methods

***

Youmi voice engine SDK for unreal engine 4 provides C + + and blueprint interfaces. Interface calls will be returned immediately. Any interface calls that need a long time will be called asynchronously. All interfaces can be used directly in the main thread. The callback is in the main thread.

## API call description

***

The basic process of API usage is as follows: (initialization → receiving callback notification of successful initialization → joining language channel → receiving callback notification of successful channel joining → using other interfaces → leaving voice channel → de initialization). It is necessary to ensure that the interfaces are used in strict accordance with the above sequence.

## Binding callback

****

- ### Interface definition

  ```C++
  /**
  *  funcDesc: Bind observer in callback
  *  @param  Observer: YouMeTalkObserver interface
  */
  UFUNCTION(BlueprintCallable, Category = "YouMeTalkAPI")
  	static void BindObserver(TScriptInterface<IYouMeTalkObserver> Observer);
  ```

- ### Function

  Object used to bind listening callbacks.

- ### Parameter description

  `Observer`：Inherits the class of **IYouMeTalkObserver** .

- ### Blueprint usage

  1. Inherit the **YoumeTalkObserver** interface in the **ClassSettings** Option of the blueprint, as shown in the following figure:

     ![image-20210706143937430](/Images/image_6.png)

     

     ![image-20210706143824326](/Images/image_7.png)

  2. In the blueprint, we call the **BindObserver** blueprint node, as shown in the following figure:

![image-20210706144238413](/Images/image_8.png)

 

- ### C + + usage

  1. Inherit the callback interface **IYouMeTalkObserver**, and pay attention to the header file.

     ![image-20210707154001415](/Images/image_9.png)
  
  2. Import header file（ Introduced (negligible)

     ```C++
     #include "YouMeTalkAPI.h"
     ```
  
  3. Call the **BindObserver** interface.

     ```c++
     UYouMeTalkAPI::BindObserver(this);
     ```
  
- When Binding callback listening, only one object is allowed to listen.



## Callback monitoring

***

- ### Interface definition

  ```C++
  /**
  *  funcDesc: event callback
  *  @param  event: callback event type
  *  @param  error: YOUME_SUCCESS - Success
  				 Other - Specific error code
  *  @param  channel: call channel
  *  @param  param: other param
  */
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "YouMeTalkAPI")
  	void OnEvent(const EYouMeEvent event, const EYouMeErrorCode error, const FString& channel, const FString& param);
  ```

- ### Function

  Callback listening events are used to listen to the callbacks related to the subsequent TalkSDK operations.
  
- ### Parameter description

  - `event`：The event type of the callback
  - `error`：Error code for callback
  - `channel`：Callback channel
  - `param`：Other parameters

- ### Blueprint usage

  In the blueprint for inheriting the **YouMeTalkObserver** interface, we call the **EventOnEvent** blueprint node.

![image-20210706145856668](/Images/image_10.png)

- ### C + + usage

  In the class of inheriting callback interface **IYouMeTalkObserver**, implement **Callback event onEvent virtual function**.

  ```C++
  virtual void OnEvent_Implementation(const EYouMeEvent event, const EYouMeErrorCode error, const FString& channel, const FString& param) override;
  ```

  Note: if the callback event virtual function is implemented in C + +, do not implement it again in the blueprint. Otherwise, the callback of C + + will be overridden and C + + will not receive the callback.

- After completing the above callback event binding, API related callbacks can be implemented in subsequent API calls.

  

## Remove listening

***

- ### Interface definition

  ```C++
  /**
  *  funcDesc: Unbind observer in callback
  */
  UFUNCTION(BlueprintCallable, Category = "YouMeTalkAPI")
  	static void UnbindObserver();
  ```

- ### Function

  Unbind the listening object.
  
- ### Blueprint usage

  In the blueprint of binding listening, we call the **UnbindObserver** blueprint node and unbind it, as shown in the following figure:

![image-20210706151016776](/Images/image_11.png)

- ### C + + usage

  1. Import header file（ Introduced (negligible)

     ```
     #include "YouMeTalkAPI.h"
     ```

  2. Call the **UnbindObserver** interface.

     ```c++
     UYouMeTalkAPI::UnbindObserver();
     ```



## TalkSDK Init

***

- ### Interface definition

  ```C++
  /**
  *  funcDesc: YouMeTalk plugin init
  *  @param  strAppKey: The app key obtained when applying for SDK registration can also be sent to the http://gmx.dev.net/createApp.html query
  *  @param  strAPPSecret: The app secret obtained when applying for SDK registration can also be sent to the http://gmx.dev.net/createApp.html query
  *  @param  youMeRTCServerRegion: Server region
  *  @param  strExtServerRegionName: Server region name
  *  @return YOUME_SUCCESS - Success
  *          Other - Specific error code
  */
  UFUNCTION(BlueprintCallable, Category = "YouMeTalkAPI")
  	static EYouMeErrorCode YouMeTalkInit(const FString strAppKey, const FString strAPPSecret, EYouMeRTCServerRegion youMeRTCServerRegion, const FString strExtServerRegionName);
  ```

- ### Function

  Initialize the voice engine, do app verification and resource initialization（ Only when the appkey, appsecret and serverregionid are the same, can voice intercommunication be carried out, and any one can be regarded as another area service).

- ### Parameter description

  - `strAPPKey`：App key from the background application of the secret, this is the only ID of your application.

  - `strAPPSecret`：The private key of the corresponding strappkey should be kept properly and should not be exposed to others. 

  - `serverRegionId`：Set the area code of preferred connection server. If the area cannot be determined during initialization, RTC can be filled in_ CN_ Server, which is set by setserverregion when it is determined later. If you me_ RTC_ SERVER_ The region code defined by region can not meet the requirements, so this parameter can be set to RTC_ EXT_ Server, and then set a custom region value (such as "CN" or "ch" in China) through the following parameter strextserverregionname, and synchronize the custom region value to youmi. We will configure the server mapped to the best region through the background.

  -  `strExtServerRegionName`：Custom extended server area name. Cannot be null, can be empty string ''. Only the previous parameter serverregionid is set to RTC_ EXT_ This parameter is valid only when server is in effect (otherwise, it will be processed on empty string ''.

- ### Return value

  Back to YOUME_SUCCESS will have asynchronous callback notification.  For other return values, please refer to [YouMeErrorCode type definition](https://www.youme.im/doc/TalkCocosC++StatusCode-v2.5.php#YouMeErrorCode类型定义)。

- ### Blueprint usage

  Call **YouMeTalkInit** blueprint node.

![image-20210706153123730](/Images/image_12.png)

- ### C + + usage

  1. Import header file（ Introduced (negligible)

     ```C++
     #include "YouMeTalkAPI.h"
     ```
  
  2. Call **YouMeTalkInit** interface。
  
     ```C++
     FString strAppKey = "";
     FString strAPPSecret = "";
     EYouMeRTCServerRegion youMeRTCServerRegion = EYouMeRTCServerRegion::RTC_CN_SERVER;
     FString strExtServerRegionName = "";
     
     UYouMeTalkAPI::YouMeTalkInit(strAppKey, strAPPSecret, youMeRTCServerRegion, strExtServerRegionName);
     ```
  
     

## Talk Unlnit

***

- ### Interface definition

  ```C++
  /**
  *  funcDesc:Anti initialization engine
  *  @return YOUME_SUCCESS - Success
  *          Other - Specific error code
  */
  UFUNCTION(BlueprintCallable, Category = "YouMeTalkAPI")
  	static EYouMeErrorCode UnInit();
  ```

- ### Function

  The anti initialization engine can be called when exiting the game to release all SDK resources.

- ### Return value

  Return if successful, YOUME_SUCCESS, For other return values, please refer to [YouMeErrorCode type definition](https://www.youme.im/doc/TalkCocosC++StatusCode-v2.5.php#YouMeErrorCode类型定义)。

- ### Blueprint usage

  Call **UnInit** blueprint node.

![image-20210706154502112](/Images/image_13.png)

- ### C + + usage

  1. Import header file（ Introduced (negligible)

     ```C++
     #include "YouMeTalkAPI.h"
     ```

  2. Call **UnInit** interface。

     ```C++
     UYouMeTalkAPI::UnInit();
     ```



## JoinTalkChannel（Single Channel）

***

- ### Interface definition

  ```C++
  /**
  *  funcDesc: Join voice channel (single channel mode, only one voice channel at any time)
  *  @param  strUserID: The user ID must be globally unique
  *  @param  strChannelID: Channel ID, to ensure global uniqueness
  *  @param  userRole: User role, which is used to decide the right to speak / play background music, etc
  *  @param  bCheckRoomExist: Check whether to join only when the channel exists. The default value is false: true. Error is returned when the channel exists or does not exist (mostly for audience roles). False: join the channel regardless of whether the channel exists
  *  @return YOUME_SUCCESS - Success
  *          Other - Specific error code
  */
  UFUNCTION(BlueprintCallable, Category = "YouMeTalkAPI")
  	static EYouMeErrorCode JoinChannelSingleMode(const FString strUserID, const FString strChannelID, EYouMeUserRole userRole, bool bCheckRoomExist);
  ```

- ### Function

  Add voice channel (single channel mode, only one voice channel at any time).

- ### Parameter description

  - `strUserID`：Globally unique user ID, which is within the scope of the current application.

  - `strChannelID`：Globally unique channel ID, which is within the scope of the current application.

  - `userRole`：For the user's role in the voice channel, see the definition of youmeuserrole.

  - `bCheckRoomExist`：Whether to check whether the channel exists before joining. The default value is false: true. When the channel exists, joining or not, an error is returned (mostly for audience roles). False: join the channel regardless of whether the channel exists or not.

  Back to YouMe_ Success will have asynchronous callback notification. For other return values, please refer to [YouMeErrorCode type definition](https://www.youme.im/doc/TalkCocosC++StatusCode-v2.5.php#YouMeErrorCode类型定义).

- ### Blueprint usage

  Call **JoinChannelSingleMode** blueprint type.

![image-20210706161445437](/Images/image_14.png)

- ### C + + usage

  1. Import header file（ Introduced (negligible)
  
     ```C++
     #include "YouMeTalkAPI.h"
     ```
  
  2. Call **JoinChannelSingleMode** interface.

     ```C++
     FString strUserID = "";
     FString strChannelID = "";
     EYouMeUserRole userRol = EYouMeUserRole::YOUME_USER_HOST;
     bool bCheckRoomExis = true;
     UYouMeTalkAPI::JoinChannelSingleMode(strUserID, strChannelID, userRol, bCheckRoomExis);
     ```
  
     

## Exit all language channels

***

- ### Interface definition

  ```C++
  /**
  *  funcDesc: Exit all voice channels
  *  @return YOUME_SUCCESS - Success
  *          Other - Specific error code
  */
  UFUNCTION(BlueprintCallable, Category = "YouMeTalkAPI")
  	static EYouMeErrorCode LeaveChannelAll();
  ```

- ### Function

  In multi-channel mode, exit the specified voice channel.

- ### Parameter description

  - `strChannelID`：Globally unique channel ID, which is within the scope of the current application.

- ### Return value

  Back to YouMe_ Success will have asynchronous callback notification. For other return values, please refer to [YouMeErrorCode type definition](https://www.youme.im/doc/TalkCocosC++StatusCode-v2.5.php#YouMeErrorCode类型定义).

- ### Asynchronous callback

  The main callback events involved are:

  - YOUME_EVENT_LEAVED_ONE - Successfully exited the specified voice channel.

- ### Blueprint usage

  Call **LeaveChannelAll** blueprint node.

![image-20210706163317849](/Images/image_15.png)

- ### C + + usage

  1. Import header file（ Introduced (negligible)
  
     ```c++
     #include "YouMeTalkAPI.h"
     ```
  
  2. Call **LeaveChannelAll** interface。
  
     ```C++
     UYouMeTalkAPI::LeaveChannelAll();
     ```



## Set White User List

***

- ### Interface definition

  ```C++
  /**
  *  funcDesc: Set whitelist users for channels
  *  @param strChannelID: Channel to set
  *  @param vecWhiteUserList: White list user list
  *  @return YOUME_SUCCESS - Success
  *          Other - Specific error code
  */
  UFUNCTION(BlueprintCallable, Category = "YouMeTalkAPI")
  	static EYouMeErrorCode SetWhiteUserList(const FString strChannelID, const FString vecWhiteUserList);
  ```

- ### Function

  If the current user's voice message receiving white list is set, the voice message will only be forwarded to the user in the white list. If the interface is not set, it will be forwarded to everyone in the channel by default.

- ### Parameter description

  - `strChannelID`：The channel to be set (compatible with multi-channel mode, just pass in the current channel in single channel mode).
  - `strWhiteUserList`：The list of white list users is separated by | for example: user1 | user2| user3; "All" means forwarding to all people in the channel; ''（ Empty string) means that it is not forwarded to any user.

- ### Return value

  Back to YouMe_ Success will have asynchronous callback notification. For other return values, please refer to [YouMeErrorCode type definition](https://www.youme.im/doc/TalkCocosC++StatusCode-v2.5.php#YouMeErrorCode类型定义).

- ### Asynchronous callback

  The main callback events involved are:

  - YOUME_EVENT_SET_WHITE_USER_LIST_OK - If the white list is set successfully in the specified voice channel, the abnormal user will return an error code YOUME_ERROR_WHITE_SOMEUSER_ABNORMAL.
  - YOUME_EVENT_SET_WHITE_USER_LIST_FAILED - Failed to set the white list in the specified voice channel, possibly due to network or server problems.

- ### Blueprint usage

  Call **SetWhiteUserList** blueprint node.

![image-20210706164212503](/Images/image_16.png)

- ### C + + usage

  1. Import header file（ Introduced (negligible)
  
     ```
     #include "YouMeTalkAPI.h"
     ```
  
  2. Call **SetWhiteUserList** Interface。
  
     ```C++
     FString strChannelID = "";
     FString vecWhiteUserList = "";
     
     UYouMeTalkAPI::SetWhiteUserList(strChannelID, vecWhiteUserList);
     ```



## Set Speaker Mute

***

- ### Interface definition

  ```C++
  /**
  *  funcDesc: Mute speakers
  *  @param mute: True -- mute, false -- unmute
  */
  UFUNCTION(BlueprintCallable, Category = "YouMeTalkAPI")
  	static void SetSpeakerMute(bool mute);
  ```

- ### Function

  Turn on / off the speaker. The status value is set only after the room is joined successfully（ The interface is asynchronous and will take effect for a period of time after being called.)

- ### Parameter description

  `mute`：true——Close Speaker，false——Open Speaker。

- ### Blueprint usage

  ![image-20210706175311140](/Images/image_17.png)

- ### C + + usage

  1. Import header file（ Introduced (negligible)
  
     ```c++
     #include "YouMeTalkAPI.h"
     ```

  2. Call **SetSpeakerMute** Interface。
  
     ```c++
     bool mute = true;
     
     UYouMeTalkAPI::SetSpeakerMute(mute);
     ```
  
  

## Get Speaker Status

***

- ### Interface definition

  ```C++
  /**
  *  funcDesc: Get speaker mute status
  *  @return True -- mute, false -- unmute
  */
  UFUNCTION(BlueprintCallable, Category = "YouMeTalkAPI")
      static bool GetSpeakerMute();
  ```

- ### Function

  Gets the current microphone status（ The interface is asynchronous, so it is avoided to call the interface immediately after setting the speaker state logically.

- ### Return value

  `Value`：true——Close Microphone，false——Open Microphone。

- ### Blueprint usage

  Call **GetSpeakerMute** blueprint node.

  ![image-20210706175822609](/Images/image_18.png)

- ### C++ usage

  1. Import header file（ Introduced (negligible)
  
     ```C++
     #include "YouMeTalkAPI.h"
     ```
  
  2. 调用 **GetSpeakerMute** Interface。
  
     ```C++
     UYouMeTalkAPI::GetSpeakerMute();
     ```



## Set volume

***

- ### Interface definition

  ```C++
  /**
  *  funcDesc: Increase the volume by 1
  *  @param uiVolume: volume
  */
  UFUNCTION(BlueprintCallable, Category = "YouMeTalkAPI")
  	static void SetVolume(const int32 &uiVolume);
  ```

- ### Function

  Set the current program output volume. It is suggested that the status value should be reset again as needed after successfully joining the room.

- ### Parameter description

  `uiVolume`:Current volume, range [0-100].

- ### Blueprint usage

  Call **SetVolume** blueprint node.

  ![image-20210706180112430](/Images/image_19.png)

- ### C + + usage

  1. Import header file（ Introduced (negligible)
  
     ```c++
     #include "YouMeTalkAPI.h"
     ```
  
  2. Call **SetVolume** Interface。
  
     ```C++
     int32 uiVolume = 50;
     UYouMeTalkAPI::SetVolume(uiVolume);
     ```



## Get Volume

***

- ### Interface definition

  ```C++
  /**
  *  funcDesc: Get the volume value, which is the volume inside the program, and multiply it with the system volume to get the actual volume used by the program
  *  @return Volume value [0-100]
  */
  UFUNCTION(BlueprintCallable, Category = "YouMeTalkAPI")
  	static int32 GetVolume();
  ```

- ### Function

  Get the current program output volume.

- ### Return value

  `Value`：Current volume, range [0-100].

- ### Blueprint usage

  Call **Get Volume** blueprint node

  ![image-20210706180551024](/Images/image_20.png)

- ### C + + usage

  1. Import header file（ Introduced (negligible)

     ```C++
     #include "YouMeTalkAPI.h"
     ```

  2. Call **GetVolume** Interface。

     ```C++
     UYouMeTalkAPI::GetVolume();
     ```

  

## Pause the call

***

- ### Interface definition

  ```C++
  /**
  *  funcDesc: Pause the call and release the microphone and other device resources
  *  @return YOUME_SUCCESS - SuccessC++
  *          Other - Specific error code
  */
  UFUNCTION(BlueprintCallable, Category = "YouMeTalkAPI")
  	static EYouMeErrorCode PauseChannel();
  ```

- ### Function

  Pause the call and release the use of the microphone and other equipment resources. This interface can be called when temporary recording is required with a third-party module.

- ### Return value

  Back to YouMe_ Success will have asynchronous callback notification. For other return values, please refer to [YouMeErrorCode type definition](https://www.youme.im/doc/TalkCocosC++StatusCode-v2.5.php#YouMeErrorCode类型定义).

- ### Asynchronous callback

  YOUME_EVENT_RESUMED - Resume voice channel complete。

- ### Blueprint usage

  Call **PauseChannel** blueprint node.

  ![image-20210706181707718](/Images/image_21.png)

- ### C + + usage

  1. Import header file（ Introduced (negligible)
  
     ```C++
     #include "YouMeTalkAPI.h"
     ```
  
  2. Call **PauseChannel** Interface。
  
     ```c++
     UYouMeTalkAPI::PauseChannel();
     ```
  
  

## Resume call

***

- ### Interface definition

  ```C++
  /**
  *  funcDesc: Resume call
  *  @return YOUME_SUCCESS - Success
  *          Other - Specific error code
  */
  UFUNCTION(BlueprintCallable, Category = "YouMeTalkAPI")
  	static EYouMeErrorCode ResumeChannel();
  ```

- ### Function

  Resume the call. After pausechannel is called to pause the call, this interface can be called to resume the call.

- ### Return value

  Back to YOUME_ SUCCESS will have asynchronous callback notification.

- ### Asynchronous callback

  YOUME_EVENT_RESUMED - Resume voice channel complete.

- ### Blueprint usage

  Call **ResumeChannel** blueprint node.

  ![image-20210706182043884](/Images/image_22.png)

- ### C + + usage

  1. Import header file（ Introduced (negligible)
  
     ```C++
     #include "YouMeTalkAPI.h"
     ```
  
  2. Call **ResumeChannel** Interface。
  
     ```c++
     UYouMeTalkAPI::ResumeChannel();
     ```



## Play background music

***

- ### Interface definition

  ```c++
  /**
  *  funcDesc: Play background music and allow selection to blend to speaker output and microphone input
  *  @param pFilePath: Path to music files
  *  @param bRepeat: Repeat
  *  @return YOUME_SUCCESS - Success
  *          Other - Specific error code
  */
  UFUNCTION(BlueprintCallable, Category = "YouMeTalkAPI")
  	static EYouMeErrorCode PlayBackgroundMusic(const FString pFilePath, bool bRepeat);
  ```

- ### Function

  Play the specified music file. The music will be output through the loudspeaker and mixed with the voice and sent to the receiver. This function can only be used when you enter the channel as the anchor / conductor.

- ### Parameter description

  - `pFilePath`：The path to the music file.
  -  `bRepeat`：Repeat or not, true - repeat, false - stop only once.

- ### Return value

  Back to YOUME_SUCCESS will have asynchronous callback notification. 

- ### Asynchronous callback

  - YOUME_EVENT_BGM_STOPPED - Notify the end of background music
  - YOUME_EVENT_BGM_FAILED - Notification of background music playback failure

- ### Blueprint usage

  Call **PlayBackgroundMusic** blueprint node.

  ![image-20210706182614536](/Images/image_23.png)

- ### C + + usage

  1. Import header file（ Introduced (negligible)
  
     ```C++
     #include "YouMeTalkAPI.h"
     ```
  
  2. Call **PlayBackgroundMusic** Interface。
  
     ```C++
     FString pFilePath = "";
     bool bRepeat = true;
     
     UYouMeTalkAPI::PlayBackgroundMusic(pFilePath, bRepeat);
     ```
  
     

## Stop playing background music

***

- ### Interface definition

  ```C++
  /**
  *  funcDesc: Stop playing if background music is currently playing
  *  @return YOUME_SUCCESS - Success
  *          Other - Specific error code
  */
  UFUNCTION(BlueprintCallable, Category = "YouMeTalkAPI")
      static EYouMeErrorCode StopBackgroundMusic();
  ```

- ### Function

  Stop playing background music that is currently playing. This is a synchronous interface call. When the function returns, the music playback stops.

- ### Parameter description

  `vol`:  Volume of background music, range [0-100].

- ### Return value

  If it is successful (indicating that the background music has been stop successfully), return to youme_ Success, otherwise the error code is returned, please refer to [YouMeErrorCode type definition](https://www.youme.im/doc/TalkCocosC++StatusCode-v2.5.php#YouMeErrorCode类型定义).

- ### Blueprint usage

  Call **StopBackgroundMusic** blueprint node.

  ![image-20210706184723391](/Images/image_24.png)

- ### C + + usage

  1. Import header file（ Introduced (negligible)
  
     ```C++
     #include "YouMeTalkAPI.h"
     ```
  
  2. Call **StopBackgroundMusic** Interface。
  
     ```
     UYouMeTalkAPI::StopBackgroundMusic();
     ```
  
  

## Set background music playback volume

- ### Interface definition

  ```C++
  /**
  *  funcDesc: Set the volume of background music
  *  @param vol: Background music volume, range 0-100
  *  @return YOUME_SUCCESS - Success
  *          Other - Specific error code
  */
  UFUNCTION(BlueprintCallable, Category = "YouMeTalkAPI")
  	static EYouMeErrorCode SetBackgroundMusicVolume(int32 vol);
  ```

- ### Function

  Set the volume of the background music. This interface is used to adjust the relative volume between the background music and the voice, so that the background music and the voice mix sound coordinated. This is a synchronous call to the interface.

- ### Parameter description

  `vol`:  Volume of background music, range [0-100].

- ### Return value

  If it is successful (indicating that the volume of background music has been set successfully), return to youme_ Success, otherwise the error code is returned, please refer to [YouMeErrorCode type definition](https://www.youme.im/doc/TalkCocosC++StatusCode-v2.5.php#YouMeErrorCode类型定义).

- ### Blueprint usage

  Call **SetBackgroundMusicVolume** blueprint node.

  ![image-20210706185529784](/Images/image_25.png)

- ### C + + usage

  1. Import header file（ Introduced (negligible)
  
     ```C++
     #include "YouMeTalkAPI.h"
     ```

  2. Call **SetBackgroundMusicVolume** Interface。
  
     ```C++
     int32 vol = 50;
     
     UYouMeTalkAPI::SetBackgroundMusicVolume(vol);
     ```
  
  

## Query channel user list

***

- ### Interface definition

  ```c++
  /**
  *  funcDesc: Query the user list of the channel
  *  @param pChannelID: Channel ID to query
  *  @param maxCount: The maximum number you want to get, - 1 means get all
  *  @param notifyMemChange: Do other users need to be informed when they enter or leave the room
  *  @return YOUME_SUCCESS - Success
  *          Other - Specific error code
  */
  UFUNCTION(BlueprintCallable, Category = "YouMeTalkAPI")
  	static EYouMeErrorCode GetChannelUserList(const FString  channelID, int32 maxCount, bool notifyMemChange);
  ```

- ### Function

  Query the current user list of the channel, and set whether to get the notification of channel user in and out（ You have to be on the channel yourself)

- ### Parameter description

  - `channelID`：Channel ID。 
  - `maxCount`：The maximum number of people you want to get- 1 means to get all the lists。 
  - `notifyMemChange`：Whether other users need to be informed when entering or leaving the room（ If it is set to true, the corresponding callback will be generated when someone enters or leaves the channel. Otherwise, if it is set to false, there will be no corresponding callback.).

- ### Return value

  Back to YouMe_ Success will have asynchronous callback notification. For other return values, please refer to [YouMeErrorCode type definition](https://www.youme.im/doc/TalkCocosC++StatusCode-v2.5.php#YouMeErrorCode类型定义).

- ### Blueprint usage

  Call **GetChannelUserList** blueprint node.

  ![image-20210706192241225](/Images/image_26.png)

- ### C + + usage

  1. Import header file（ Introduced (negligible)
  
     ```C++
     #include "YouMeTalkAPI.h"
     ```
  
  2. Call **GetChannelUserList** Interface。
  
     ```C++
     FString  channelID = "";
     int32 maxCount = 10;
     bool notifyMemChange = true;
     
     UYouMeTalkAPI::GetChannelUserList(channelID, maxCount, notifyMemChange);
     ```



## Broadcast news

***

- ### Interface definition

  ```C++
  /**
  *  funcDesc: Broadcast a message to the room
  *  @param pChannelID: Broadcasting room
  *  @param pContent: Broadcast content - text string
  *  @param requestID: Returns the message ID, which will be returned during callback
  *  @return YOUME_SUCCESS - Success
  *          Other - Specific error code
  */
  UFUNCTION(BlueprintCallable, Category = "YouMeTalkAPI")
  	static EYouMeErrorCode SendMessage(const FString pChannelID, const FString pContent, int32 requestID);
  ```

- ### Function

  In the voice channel, broadcast a text message.

- ### Parameter description

  - `pChannelID`：Channel ID (you need to enter this channel).
  - `pContent`：The text content to broadcast.
  - `requestID`：The ID used to identify the message.

- ### Return value

  Back to YouMe_ Success will have asynchronous callback notification. For other return values, please refer to [YouMeErrorCode type definition](https://www.youme.im/doc/TalkCocosC++StatusCode-v2.5.php#YouMeErrorCode类型定义).

- ### Asynchronous callback

  The sender will receive YOUME_EVENT_SEND_MESSAGE_RESULT callback，notifies the result of sending the message. Other people in the channel receivedYOUME_EVENT_MESSAGE_NOTIFY callback，notify callback to notify message content.

  - event:YOUME_EVENT_SEND_MESSAGE_RESULT: Result callback of sending message，Param is the string of requestid
  - event:YOUME_EVENT_MESSAGE_NOTIFY: Other people in the channel are notified of the message. Param is the text content
  
- ### Blueprint usage

  Call **SendMessage** blueprint node.

  ![image-20210707102953612](/Images/image_27.png)

- ### C + + usage

  1. Import header file（ Introduced (negligible)

     ```c++
     #include "YouMeTalkAPI.h"
     ```

  2. Call **SendMessage** Interface。

     ```C++C++
     FString pChannelID = "";
     FString pContent = "";
     int32 requestID = 1;
     
     UYouMeTalkAPI::SendMessage(pChannelID, pContent, requestID);
     ```

  

## Kick people out of the room

***

- ### Interface definition

  ```C++
  /**
  *  funcDesc: Kick sb out of the room
  *  @param  pUserID: Kicked user ID
  *  @param  pChannelID: From which room
  *  @param  lastTime: After kicking out, how long is it not allowed to enter again
  *  @return YOUME_SUCCESS - Success
  *          Other - Specific error code
  */
  UFUNCTION(BlueprintCallable, Category = "YouMeTalkAPI")
  	static EYouMeErrorCode KickOtherFromChannel(const FString pUserID, const FString pChannelID, int32 lastTime);
  ```

- ### Function

  Kick people out of the room.

- ### Parameter description

  - `pUserID`：The user ID being kicked. 
  - `pChannelID`：Kick out of which room (you need to be in the room). 
  - `lastTime`：After kicking out, how long is it not allowed to enter again (unit: seconds).

  

- ### Return value

  Back to YouMe_ Success will have asynchronous callback notification. For other return values, please refer to [YouMeErrorCode type definition](https://www.youme.im/doc/TalkCocosC++StatusCode-v2.5.php#YouMeErrorCode类型定义).

- ### Asynchronous callback
  
  - event:YOUME_EVENT_KICK_RESULT: The kicker receives the message and sends the result callback. Param is the ID of the kicker.
  - event:YOUME_EVENT_KICK_NOTIFY: When the kicked party receives the kick notice, it will automatically exit the channel. Param: (kicker ID, reason of being kicked, time of being banned).

- ### Blueprint usage

  Call **KickOtherfromChannel** blueprint node.

  ![image-20210707103316119](/Images/image_28.png)

- ### C + + usage

  1. Import header file（ Introduced (negligible)

     ```C++
     #include "YouMeTalkAPI.h"
     ```

  2. Call **KickOtherfromChannel** Interface。

     ```C++
     FString pUserID = "";
     FString pChannelID = "";
     int32 lastTime = 10;
     
     UYouMeTalkAPI::KickOtherfromChannel(pUserID, pChannelID, lastTime);
     ```
