
    Dim xml, str_html
    Dim str_date, str_time

    Set xml = CreateObject("Microsoft.XMLHTTP")

    With xml
        .Open "GET", "http://time.tianqi.com/", False
        .send
        str_html = .responsetext
    End With

    str_html = Split(str_html, "，北京现在时间：")(1)
    str_date = Left(str_html, 10)
    str_time = Mid(str_html, 12, 8)

    set objShell=wscript.createObject("wscript.shell")
    objShell.Run("cmd.exe /c Date " & str_date)
    objShell.Run("cmd.exe /c Time " & str_time)

    wscript.quit