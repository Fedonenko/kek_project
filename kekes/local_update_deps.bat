time /t

set CONF=%1
set DEPS_DIR=.\deps\

set CONAN_HOME=C:\c

if not defined CONF (
    goto default_conf
) else (
    echo "You use configuration %CONF%."
    goto configure
)

:default_conf
SET CONF=Debug
echo "You use default configuration %CONF%. You can use argument Debug or Released."

:configure

rem goto end

rem pip install --upgrade pip
python -m venv tmpEnv

CALL ".\tmpEnv\Scripts\activate"

python -m pip install --upgrade pip
rem pip install html5lib

pip install conan

conan install %DEPS_DIR% -s build_type=%CONF% -of=conan/%CONF% --build=missing --profile %DEPS_DIR%%CONF%_prf

CALL ".\tmpEnv\Scripts\deactivate"

:end

time /t

rem time /t > time_done.txt

rem shutdown -s -f -t 0