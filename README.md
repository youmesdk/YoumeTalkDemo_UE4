- # Talk SDK Demo for UnrealEngine4 使用指南

  ## Demo概述

  ***

  本Demo是YoumeTalk的UE4_4.24版本。

  

  ## Demo使用

  ***

  1. 生成文件结构，并编译工程。

     ![image_1](Images\image_1.png)

     

     ![image-20210706110737713](/Images/image_3.png)

  2. 蓝图中引入插件：打开UE4引擎编辑器，在（Edit | Plugins | Project | Other）选项中勾选启用YouMeTalk插件，重启引擎，即可使用插件。

     ![image-20210706111009744](/Images/image_4.png)

  3. C++中引入插件：打开工程的Visual Studio，在工程主模块的build.cs（文件路径：[ ProjectName / Source / ProjectName / ]）文件中，包含TalkSDK插件，代码如下：

  ```C++
  PrivateDependencyModuleNames.AddRange(new string[] { "YouMeTalk" });
  ```

  ## API接口调用流程

  ***

  API调用的基本流程如下图所示，具体接口说明参见 <u>**TalkSDKforUnrealEngine4 API接口手册**</u>。

  ![img](/Images/image_5.png)

  