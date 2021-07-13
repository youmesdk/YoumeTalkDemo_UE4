- # Talk SDK for UnrealEngine4 Guide to use

  ## Scope if application

  ***

  This document is only suitable for developers who use the Unreal Engine 4 plug-in (c++ interface and blueprint interface) to develop multi-human real-time voice function.

  

  ## SDK directory overview

  ***

  The talk SDK is integrated into Unreal Engine 4 in the form of plug-in. The file format of the plug-in is as follows:

  ├─ YouMeTalk
      ├─ Content
      ├─ Resources
      ├─ Source
      	├─ YouMeTalk
     	     ├─ Private
      		├─ Public
      		├─ YouMeTalkLibrary
      			├─ include
      			└─ lib

  - Content：Contains a demo using the talk SDK, using the blueprint method to quickly demonstrate how to use the talk SDK.
  - Resources：Contains plug-in resource files, such as plug-in cover map.
  - Public：Encapsulates the header file of the talksdk interface available to UE4.
  - Private：Package UE4 available talk SDK interface source code.
  - include：The header file of the original interface of talksdk.
  - lib：The library file of the original interface of talksdk is divided into Android platform and IOS platform. The Android platform includes libyoume_voice_engine.so file with armv5, armv7 and x86 CPU architectures，And youme_ voice_ engine.jar。The IOS platform includes libyoume_voice_engine.a and libYouMeCommon.a file.

  

  ## Development environment integration

  ***

  1. Copy the youmetalk plugin to the plugins folder in the project root directory, as shown in the following figure（ If there is no plugins folder, create one)

     ![image-20210706105939642](/Images/image_1.png)

  2. Rebuild the file structure and compile the project.

     ![image-20210706110619003](/Images/image_2.png)

     ![image-20210706110737713](/Images/image_3.png)

  3. Plugin in the blueprint: open the UE4 engine editor, and check the enable youmeta plugin in the (edit | plugins | project | other) option, restart the engine, and then use the plug-in.

     ![image-20210706111009744](/Images/image_4.png)

  4. C + + plugin: open the visual studio of the project, and include the talk SDK plugin in the build.cs (file path: [ProjectName / source / ProjectName /]) file of the main module of the project. The code is as follows:

  ```C++
  PrivateDependencyModuleNames.AddRange(new string[] { "YouMeTalk" });
  ```

  

  ## API interface call process

  ***

  The basic flow of API call is shown in the figure below. For specific interface description, see <u>**Talk SDK for UnrealEngine4 API Interface Manual**</u>.

  ![img](/Images/image_5.png)

  