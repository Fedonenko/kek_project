rem python -m pip install --upgrade pip
python -m venv tmpEnv

CALL ".\tmpEnv\Scripts\activate"

pip install conan==2.10.1

conan install . -s build_type=Debug -of=conan/debug --build=missing --profile debug_prf
conan install . -s build_type=Release -of=conan/release --build=missing --profile release_prf