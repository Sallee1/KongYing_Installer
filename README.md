# 空荧酒馆原神地图安装器

本安装器基于C++和Qt5开发，基于天理安装器为模板修改

[天理安装器项目地址](https://github.com/WeiXiTianLi/TianLi.Installer)

![image](https://user-images.githubusercontent.com/99392726/230767335-aa30d660-f6d4-43b7-9364-9aa269cd398e.png)

感谢7Zip，Resource hacker, Gnu, [icomake](https://github.com/tringi/icomake)等开源项目为打包提供的帮助。


## 功能亮点

* 智能识别安装环境，自动切换安装、升级、卸载功能
* 智能识别安装路径，自动创建文件夹或覆盖升级，避免将文件无意安装到非空文件夹中
* 支持添加快捷方式和卸载功能
* 使用配置文件可以控制写入注册表的信息

## 如何打包《空荧酒馆原神地图》
1. 下载最新构建
2. 把《空荧酒馆原神地图》的程序放在`data/package/`文件夹中
3. 修改Installer.json，键值如下

**RegInfo**：注册表相关配置
| 值 | 说明 |
|---|---|
|displayName|在“程序与功能”中显示的软件名称|
|displayVersion|在“程序与功能”中显示的软件版本|
|publisher|在“程序与功能”中显示的发布者|
|displayIcon|在“程序与功能”中显示的图标，相对软件安装目录|
|uninstallString|卸载命令，相对于安装目录|
|UserDataLocation|用户数据目录，对应卸载器“删除本地用户数据”功能|
|URLInfoAbout|关于中的链接，可不填|
|HelpLink|关于中的链接，可不填|
|URLUpdateInfo|关于中的链接，可不填|
|estimatedSize| 估计的软件大小，单位为KiB|

**InstallerGlobal**：安装器相关配置
| 值 | 说明 |
|---|---|
|defaultInstallPath|默认安装路径|
|desktopShortcut|默认是否安装桌面快捷方式|
|desktopShortcut_name|桌面快捷方式的名称|
|startmenuShortcut|默认是否安装开始菜单快捷方式|
|startmenuShortcut_foldername|开始菜单文件夹的名称|
|startmenuShortcut_programName|开始菜单启动程序的名称|
|startmenuShortcut_uninstallName|开始菜单卸载程序的名称|
|exePath|快捷方式指向的可执行程序的路径，相对软件安装目录|
|existFileName|覆盖安装检测数组，只有列表中的文件都存在，才会识别为覆盖安装，否则会创建新文件夹|

4. 在resource中，放置Logo文件，格式可参考内置示例
5. 运行pack.bat，等待命令执行完成，输出installer.exe

## 我想打包自己的软件
* 本项目需要使用Qt5静态库，
* 修改 Form File中的tianli_widget.ui以修改安装器显示的文本
* 修改 Resource Files 中的Resource来更改外观
* 编译，在release模式下，输出的install.exe将会出现在release/tianli文件夹中
* 替换data文件夹的install.exe

修改时请遵守LGPL协议
