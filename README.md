A very simple program intended to keep WSL alive when executed via a scheduled task, service, or manual execution.  The executable first creates a lock file in /tmp to ensure the program is only executed once.  It then sleeps infinitely.  If another instance is started, it will fail to get a lock on the lock file and exit.  This allows the program to be executed multiple times without worrying about ending up with many instances running.

This program is necessary because WSL shuts itself down when not in use by an interactive session, or something like that.  This behavior is documented in various issues in Microsoft's WSL repo on Github.

Example configuration file for [WinSW](https://github.com/winsw/winsw):
```xml
<service>
  <id>WSL</id>
  <name>WSL</name>
  <description>This service runs WSL.</description>

  <logpath>%BASE%\log</logpath>
  <executable>C:\Program Files\WSL\wsl.exe</executable>
  <arguments>~/git/wsl/wsl</arguments>

  <serviceaccount>
    <user>username</user>
  </serviceaccount>

  <log mode="roll-by-time">
    <pattern>yyyyMMdd</pattern>
    <keepFiles>7</keepFiles>
  </log>
</service>
```
