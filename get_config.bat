@echo off
:main_menu
cls
echo ============================
echo    Windows Utility Menu
echo ============================
echo 1. Display IP Address
echo 2. Perform Traceroute
echo 3. Resolve DNS Name
echo 4. Encrypt Text (Unsupported)
echo 5. Decrypt Text (Unsupported)
echo 6. Encrypt File (Unsupported)
echo 7. Decrypt File (Unsupported)
echo 8. Compress File (LZ77)
echo 9. Decompress File
echo 10. Calculate Hash Value (Text/File)
echo 0. Exit
echo ============================
set /p option="Choose an option: "

if "%option%"=="1" goto show_ip
if "%option%"=="2" goto do_traceroute
if "%option%"=="3" goto resolve_dns_name
if "%option%"=="4" goto enc_text
if "%option%"=="5" goto dec_text
if "%option%"=="6" goto enc_file
if "%option%"=="7" goto dec_file
if "%option%"=="8" goto comp_file
if "%option%"=="9" goto decomp_file
if "%option%"=="10" goto hash_val
if "%option%"=="0" goto end
goto main_menu

:show_ip
echo IPv4 Address:
ipconfig | findstr /i "ipv4"
echo IPv6 Address:
ipconfig | findstr /i "ipv6"
pause
goto main_menu

:do_traceroute
set /p host="Enter the host or IP: "
tracert %host%
pause
goto main_menu

:resolve_dns_name
set /p dns="Enter the DNS name: "
nslookup %dns%
pause
goto main_menu

:enc_text
set /p input_text="Enter text to encrypt: "
echo Blowfish and Caesar encryption not available natively.
echo Please use external tools or scripts.
pause
goto main_menu

:dec_text
set /p input_text="Enter text to decrypt: "
echo Blowfish and Caesar decryption not available natively.
echo Please use external tools or scripts.
pause
goto main_menu

:enc_file
set /p file_path="Enter the file path to encrypt: "
echo File encryption requires external tools.
pause
goto main_menu

:dec_file
set /p file_path="Enter the file path to decrypt: "
echo File decryption requires external tools.
pause
goto main_menu

:comp_file
set /p file_path="Enter the file path to compress: "
echo LZ77 compression requires external tools or scripts.
pause
goto main_menu

:decomp_file
set /p file_path="Enter the file path to decompress: "
echo LZ77 decompression requires external tools or scripts.
pause
goto main_menu

:hash_val
set /p item="Enter text or file path: "
:: Using certutil for hashing.
echo Default Hashing. Result saved in def-hash-%item%
certutil -hashfile %item% > def-hash-%item%
echo Calculating MD5 Hash. Result saved in MD5-%item%
certutil -hashfile %item% MD5 > MD5-%item%
echo Calculating SHA256 Hash. Result saved in SHA256-%item%
certutil -hashfile %item% SHA256 > SHA256-%item%
pause
goto main_menu

:end
echo Exiting... See you soon!
::exit
