time /t

set CONF=%1

if not defined CONF (

goto default_conf

) else (
echo "You use configuration %CONF%."

goto configure
)

:default_conf

SET CONF=Debug

echo "You use default configuration %CONF%. You can use argument Debug or Relased."

:configure

rem goto end

rem python -m pip install --upgrade pip
python -m venv tmpEnv

CALL ".\tmpEnv\Scripts\activate"

pip install conan==2.10.1

conan install . -s build_type=%CONF% -of=conan/%CONF% --build=missing --profile %CONF%_prf

:end

time /t