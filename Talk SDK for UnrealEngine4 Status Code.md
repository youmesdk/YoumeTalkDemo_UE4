# Talk SDK for UnrealEngine4 Status Code

## YouMeEvent type definition

| Enumeration constant                   | Value | Meaning                                                      |
| -------------------------------------- | :---: | ------------------------------------------------------------ |
| YOUME_EVENT_INIT_OK                    |   0   | SDK initialized successfully                                 |
| YOUME_EVENT_INIT_FAILED                |   1   | SDK initialization failed                                    |
| YOUME_EVENT_JOIN_OK                    |   2   | Entering voice channel successfully                          |
| YOUME_EVENT_JOIN_FAILED                |   3   | Failed to enter voice channel                                |
| YOUME_EVENT_LEAVED_ONE                 |   4   | Exit single voice channel complete                           |
| YOUME_EVENT_LEAVED_ALL                 |   5   | Exit all voice channels complete                             |
| YOUME_EVENT_PAUSED                     |   6   | Pause voice channel complete                                 |
| YOUME_EVENT_RESUMED                    |   7   | Resume voice channel complete                                |
| YOUME_EVENT_SPEAK_SUCCESS              |   8   | Switch to speak to the specified channel successfully (applicable to multi-channel mode) |
| YOUME_EVENT_SPEAK_FAILED               |   9   | Failed to switch to speak to the specified channel (for multi-channel mode) |
| YOUME_EVENT_RECONNECTING               |  10   | It's disconnected. It's reconnecting                         |
| YOUME_EVENT_RECONNECTED                |  11   | Disconnection and reconnection successful                    |
| YOUME_EVENT_REC_PERMISSION_STATUS      |  12   | Inform the recording permission status, and the error code is YOUME_SUCCESS when the permission is successfully obtained,  get failed as YOUME_ERROR_REC_NO_PERMISSION (at this time, there is no sound output regardless of the microphone mute state) |
| YOUME_EVENT_BGM_STOPPED                |  13   | Notify the end of background music                           |
| YOUME_EVENT_BGM_FAILED                 |  14   | Notification of background music playback failure            |
| YOUME_EVENT_OTHERS_MIC_ON              |  16   | Other user microphone on                                     |
| YOUME_EVENT_OTHERS_MIC_OFF             |  17   | Other user microphone off                                    |
| YOUME_EVENT_OTHERS_SPEAKER_ON          |  18   | Other user speakers on                                       |
| YOUME_EVENT_OTHERS_SPEAKER_OFF         |  19   | Other user speakers off                                      |
| YOUME_EVENT_OTHERS_VOICE_ON            |  20   | Other users enter the speaking state                         |
| YOUME_EVENT_OTHERS_VOICE_OFF           |  21   | Other users are silent                                       |
| YOUME_EVENT_MY_MIC_LEVEL               |  22   | Voice level of microphone                                    |
| YOUME_EVENT_MIC_CTR_ON                 |  23   | The microphone is turned on by another user                  |
| YOUME_EVENT_MIC_CTR_OFF                |  24   | The microphone was turned off by another user                |
| YOUME_EVENT_SPEAKER_CTR_ON             |  25   | The speaker is turned on by another user                     |
| YOUME_EVENT_SPEAKER_CTR_OFF            |  26   | The speaker is turned off by another user                    |
| YOUME_EVENT_LISTEN_OTHER_ON            |  27   | Unblock sb's voice                                           |
| YOUME_EVENT_LISTEN_OTHER_OFF           |  28   | Block someone's voice                                        |
| YOUME_EVENT_LOCAL_MIC_ON               |  29   | Turn on your own microphone                                  |
| YOUME_EVENT_LOCAL_MIC_OFF              |  30   | Your microphone is off                                       |
| YOUME_EVENT_LOCAL_SPEAKER_ON           |  31   | Turn on your own speakers                                    |
| YOUME_EVENT_LOCAL_SPEAKER_OFF          |  32   | Your own speakers are off                                    |
| YOUME_EVENT_GRABMIC_START_OK           |  33   | Launched wheat snatching campaign successfully               |
| YOUME_EVENT_GRABMIC_START_FAILED       |  34   | Failed to launch wheat snatching campaign                    |
| YOUME_EVENT_GRABMIC_STOP_OK            |  35   | Stop robbing wheat successfully                              |
| YOUME_EVENT_GRABMIC_STOP_FAILED        |  36   | Failed to stop wheat snatching                               |
| YOUME_EVENT_GRABMIC_REQUEST_OK         |  37   | Winning wheat (can speak)                                    |
| YOUME_EVENT_GRABMIC_REQUEST_FAILED     |  38   | Failed to grab wheat                                         |
| YOUME_EVENT_GRABMIC_REQUEST_WAIT       |  39   | Enter the wheat grabbing waiting queue (this event will be called back only in weight mode) |
| YOUME_EVENT_GRABMIC_RELEASE_OK         |  40   | Release Mai successfully                                     |
| YOUME_EVENT_GRABMIC_RELEASE_FAILED     |  41   | Failed to release Mai                                        |
| YOUME_EVENT_GRABMIC_ENDMIC             |  42   | No longer use wheat (to wheat use time or other reasons)     |
| YOUME_EVENT_GRABMIC_NOTIFY_START       |  43   | [notice] wheat snatching starts                              |
| YOUME_EVENT_GRABMIC_NOTIFY_STOP        |  44   | [notice] the wheat snatching activity is over                |
| YOUME_EVENT_GRABMIC_NOTIFY_HASMIC      |  45   | [notice] there's wheat to rob                                |
| YOUME_EVENT_GRABMIC_NOTIFY_NOMIC       |  46   | [notice] no wheat to rob                                     |
| YOUME_EVENT_INVITEMIC_SETOPT_OK        |  47   | Lianmai set successfully                                     |
| YOUME_EVENT_INVITEMIC_SETOPT_FAILED    |  48   | Lianmai setting failed                                       |
| YOUME_EVENT_INVITEMIC_REQUEST_OK       |  49   | Successful request for Lianmai (connected, waiting for the other party's response) |
| YOUME_EVENT_INVITEMIC_REQUEST_FAILED   |  50   | Request for Lianmai failed                                   |
| YOUME_EVENT_INVITEMIC_RESPONSE_OK      |  51   | The response to Lianmai success (the called party will receive this event regardless of whether it agrees / refuses. The error code is YOUME_ERROR_INVITEMIC_REJECT Express a refusal） |
| YOUME_EVENT_INVITEMIC_RESPONSE_FAILED  |  52   | Failed to respond to Lianmai                                 |
| YOUME_EVENT_INVITEMIC_STOP_OK          |  53   | Stop Lianmai                                                 |
| YOUME_EVENT_INVITEMIC_STOP_FAILED      |  54   | Stop Lianmai failed                                          |
| YOUME_EVENT_INVITEMIC_CAN_TALK         |  55   | Both parties can talk (the responder has agreed)             |
| YOUME_EVENT_INVITEMIC_CANNOT_TALK      |  56   | The two sides can't talk any more (one of them ends the link or the link time is up) |
| YOUME_EVENT_INVITEMIC_NOTIFY_CALL      |  57   | [notice] someone asked to connect with you                   |
| YOUME_EVENT_INVITEMIC_NOTIFY_ANSWER    |  58   | [notice] the other party has responded to your request for Lianmai (agree / refuse / time out, both parties can talk if they agree) |
| YOUME_EVENT_INVITEMIC_NOTIFY_CANCEL    |  59   | [notice] in the process of continuous wheat, the other party ends continuous wheat or the time of continuous wheat is up |
| YOUME_EVENT_SEND_MESSAGE_RESULT        |  60   | sendMessage notification of success or failure，param for the return requestID |
| YOUME_EVENT_MESSAGE_NOTIFY             |  61   | received Message, param is the message content               |
| YOUME_EVENT_SET_WHITE_USER_LIST_OK     |  62   | The whitelist setting for the specified channel is successful, but there may be abnormal users |
| YOUME_EVENT_SET_WHITE_USER_LIST_FAILED |  63   | Failed to set whitelist for specified channel                |
| YOUME_EVENT_KICK_RESULT                |  64   | Kicking response                                             |
| YOUME_EVENT_KICK_NOTIFY                |  65   | Notice of being kicked out of the room                       |

## YouMeErrorCode type definition

| Enumeration constant                   | Value | Meaning                                                      |
| -------------------------------------- | :---: | ------------------------------------------------------------ |
| YOUME_SUCCESS                          |   0   | Success                                                      |
| YOUME_ERROR_API_NOT_SUPPORTED          |  -1   | The SDK you are using does not support a specific API        |
| YOUME_ERROR_INVALID_PARAM              |  -2   | Incoming parameter error                                     |
| YOUME_ERROR_ALREADY_INIT               |  -3   | Already initialized                                          |
| YOUME_ERROR_NOT_INIT                   |  -4   | It has not been initialized yet. Before calling a function, it is necessary to call initialization first, and ensure the success of initialization according to the return value |
| YOUME_ERROR_CHANNEL_EXIST              |  -5   | The channel you want to join already exists                  |
| YOUME_ERROR_CHANNEL_NOT_EXIST          |  -6   | The channel does not exist when the channel enters (when the check parameter is true), exits, talks, sets the whitelist, grabs the Mac and other interfaces |
| YOUME_ERROR_WRONG_STATE                |  -7   | Status error                                                 |
| YOUME_ERROR_NOT_ALLOWED_MOBILE_NETWROK |  -8   | Mobile network not allowed                                   |
| YOUME_ERROR_WRONG_CHANNEL_MODE         |  -9   | The multi-channel interface is called in single channel mode, or vice versa |
| YOUME_ERROR_TOO_MANY_CHANNELS          |  -10  | Too many channels at the same time                           |
| YOUME_ERROR_TOKEN_ERROR                |  -11  | Incoming token authentication error                          |
| YOUME_ERROR_NOT_IN_CHANNEL             |  -12  | The user is not on this channel                              |
| YOUME_ERROR_BE_KICK                    |  -13  | I've been kicked. I'm not allowed to enter the room during the forbidden time |
| YOUME_ERROR_MEMORY_OUT                 | -100  | Memory error                                                 |
| YOUME_ERROR_START_FAILED               | -101  | Failed to start engine                                       |
| YOUME_ERROR_STOP_FAILED                | -102  | Failed to stop engine                                        |
| YOUME_ERROR_ILLEGAL_SDK                | -103  | Illegal use of SDK                                           |
| YOUME_ERROR_SERVER_INVALID             | -104  | Voice service not available                                  |
| YOUME_ERROR_NETWORK_ERROR              | -105  | Network error                                                |
| YOUME_ERROR_SERVER_INTER_ERROR         | -106  | Server internal error                                        |
| YOUME_ERROR_QUERY_RESTAPI_FAIL         | -107  | Request for restapi information failed                       |
| YOUME_ERROR_USER_ABORT                 | -108  | The user requested to interrupt the current operation        |
| YOUME_ERROR_SEND_MESSAGE_FAIL          | -109  | Failed to send message                                       |
| YOUME_ERROR_REC_INIT_FAILED            | -201  | Failed to initialize the recording module                    |
| YOUME_ERROR_REC_NO_PERMISSION          | -202  | No recording permission                                      |
| YOUME_ERROR_REC_NO_DATA                | -203  | Although the initialization is successful, there is no audio data output. For example, when the recording permission of oppo series mobile phones is prohibited |
| YOUME_ERROR_REC_OTHERS                 | -204  | Other recording module errors                                |
| YOUME_ERROR_REC_PERMISSION_UNDEFINED   | -205  | If the recording permission is not determined, this error code is returned when IOS displays the allow recording permission dialog box |
| YOUME_ERROR_GRABMIC_FULL               | -301  | The wheat snatch failed and the number was full              |
| YOUME_ERROR_GRABMIC_HASEND             | -302  | The competition for wheat failed. The activity is over       |
| YOUME_ERROR_INVITEMIC_NOUSER           | -401  | Lianmai failed. The user does not exist                      |
| YOUME_ERROR_INVITEMIC_OFFLINE          | -402  | Failed to connect to Mac. The user is offline                |
| YOUME_ERROR_INVITEMIC_REJECT           | -403  | Lianmai failed, user refused                                 |
| YOUME_ERROR_INVITEMIC_TIMEOUT          | -404  | There are two situations: 1. When connecting to the Mac, the other party does not respond due to timeout; 2. During the call, the time for both parties to talk is up |
| YOUME_ERROR_WHITE_SOMEUSER_ABNORMAL    | -501  | Some users in white list are abnormal: they are no longer in the room |
| YOUME_ERROR_UNKNOWN                    | -1000 | Unknown error                                                |

## YOUME_RTC_SERVER_REGION type definition

| Enumeration constant | Value | Meaning                |
| -------------------- | ----- | ---------------------- |
| RTC_CN_SERVER        | 0     | China                  |
| RTC_HK_SERVER        | 1     | HongKong               |
| RTC_US_SERVER        | 2     | Eastern United States  |
| RTC_SG_SERVER        | 3     | Singapore              |
| RTC_KR_SERVER        | 4     | the republic of korea  |
| RTC_AU_SERVER        | 5     | Australia              |
| RTC_DE_SERVER        | 6     | Germany                |
| RTC_BR_SERVER        | 7     | Brazil                 |
| RTC_IN_SERVER        | 8     | India                  |
| RTC_JP_SERVER        | 9     | Japan                  |
| RTC_IE_SERVER        | 10    | Ireland                |
| RTC_USW_SERVER       | 11    | Western United States  |
| RTC_USM_SERVER       | 12    | Central America        |
| RTC_CA_SERVER        | 13    | Canada                 |
| RTC_LON_SERVER       | 14    | London                 |
| RTC_FRA_SERVER       | 15    | Frankfurt              |
| RTC_DXB_SERVER       | 16    | Dubai                  |
| RTC_EXT_SERVER       | 10000 | Using extended servers |
| RTC_DEFAULT_SERVER   | 10001 | Default server         |

## 

## YouMeKickReason type definition

| Enumeration constant | Value | Meaning                    |
| -------------------- | ----- | -------------------------- |
| YOUME_KICK_ADMIN     | 1     | Administrator kicks        |
| YOUME_KICK_RELOGIN   | 2     | Multiterminal login kicked |

## YOUME_LOG_LEVEL type definition

| Enumeration constant | Value | Meaning         |
| -------------------- | ----- | --------------- |
| LOG_DISABLED         | 0     | Disable logging |
| LOG_FATAL            | 1     | Serious error   |
| LOG_ERROR            | 10    | Error           |
| LOG_WARNING          | 20    | Warning         |
| LOG_INFO             | 40    | Information     |
| LOG_DEBUG            | 50    | Debugging       |
| LOG_VERBOSE          | 60    | All logs        |

## YOUME_SAMPLE_RATE type definition

| Enumeration constant | Value |
| -------------------- | ----- |
| SAMPLE_RATE_8        | 8000  |
| SAMPLE_RATE_16       | 16000 |
| SAMPLE_RATE_24       | 24000 |
| SAMPLE_RATE_48       | 48000 |

## YouMeUserRole type definition

| Enumeration constant        | Value | Meaning                                                      |
| --------------------------- | ----- | ------------------------------------------------------------ |
| YOUME_USER_NONE             | 0     | Illegal user. This parameter cannot be passed when calling API |
| YOUME_USER_TALKER_FREE      | 1     | Free speaker, suitable for group calls (it is recommended that the number of group members is up to 10). Everyone can speak at any time, and can only be in one voice channel at the same time |
| YOUME_USER_TALKER_ON_DEMAND | 2     | You can speak only after you ask for microphone permission by grabbing Mac. It is suitable for large groups or trade unions (such as dozens of people). Only one or several people can speak at the same time, and only one voice channel at the same time |
| YOUME_USER_LISTENER         | 3     | The audience, the audience of the anchor / conductor / guest, can only be in one voice channel at a time |
| YOUME_USER_COMMANDER        | 4     | Commanders, commanders of countries / gangs, etc., can only speak on one voice channel at a time, play background music, and monitor their own voice with headphones |
| YOUME_USER_HOST             | 5     | Anchor, the host of broadcast voice channel, can only speak in one voice channel at the same time, can play background music, and can monitor their own voice with headphones |
| YOUME_USER_GUSET            | 6     | Guests, guests invited by the anchor or conductor, can only speak on one voice channel at a time |