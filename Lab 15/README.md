# Архиватор

Параметры:

| Параметр | Описние |
|---|---|
|**--file**  *FILENAME*|*Обязательный параметр*|Имя файлового архива с которым будет работать архиватор|
|**--create** *FILE1 FILE2 …. FILEN*|Команда для создания файлового архива|
|**--extract**|Команда для извлечения из файлового архива файлов|
|**--list**|Команда для предоставления списка файлов, хранящихся в архиве|

Пример ввода в консоль:
    + programm.exe ser --file archive.ser --create a.txt b.bin c.bmp - создает файл archive.ser, который состоит из  a.txt b.bin c.bmp
    + programm.exe ser --file archive.ser --extract - извлекает все файлы в архиве archive.ser
    + programm.exe ser --file archive.ser --list - выводит в консоль содержимое архива archive.ser
