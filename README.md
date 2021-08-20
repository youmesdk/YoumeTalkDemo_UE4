- # Talk SDK Demo for UnrealEngine4 使用指南

  ## Demo概述

  ***

  本Demo提供YoumeTalk的UE4_4.24、UE4_4.25、UE4_4.26版本。

  

  ## Demo使用

  ***

  1. 初始文件结构目录

     ![image-20210820115826753](/Images/image_74.png)

  2. 点击GenerateVisualStudioProjectFiles生成Vs文件结构，生成成功后，打开UE4_YouMeTalk.sln编译工程。

     ![image-20210820120153351](/Images/image_75.png)

     ![image-20210820120235865](/Images/image_1.png)

     

     ![image-20210706110737713](/Images/image_3.png)

  3. 蓝图中引入插件：打开UE4引擎编辑器，在（Edit | Plugins | Project | Other）选项中勾选启用YouMeTalk插件，重启引擎，即可使用插件。
  
     ![image-20210706111009744](/Images/image_4.png)

  4. C++中引入插件：打开工程的Visual Studio，在工程主模块的build.cs（文件路径：[ ProjectName / Source / ProjectName / ]）文件中，包含TalkSDK插件，代码如下：

  ```C++
  PrivateDependencyModuleNames.AddRange(new string[] { "YouMeTalk" });
  ```

  ## API接口调用流程

  ***
  
  API调用的基本流程如下图所示，具体接口说明参见 -TalkSDKforUnrealEngine4 API接口手册，如何实现典型语音场景参见-TalkSDKforUnrealEngine4 典型场景实现方法
  
  ![img](/Images/image_5.png)
  
  