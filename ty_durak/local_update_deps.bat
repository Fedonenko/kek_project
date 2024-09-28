rem python -m pip install --upgrade pip
python -m venv tmpEnv

CALL ".\tmpEnv\Scripts\activate"

@rem pip install conan==1.64.1
pip install conan==2.7.0

@rem conan install conanfile.txt

@rem conan install . -s build_type=Debug -s compiler.libcxx=libc++ -s compiler.cppstd=14 --install-folder=cmake-build-debug --build missing

@rem conan install -s "build_type=Release" "--build=missing" .

@rem conan install . -s "build_type=Release"
conan install . -sbuild_type=Debug -of=conan/debug --build=missing --profile default_debug
@rem conan install . -s build_type=Release -of=conan/release --profile default_debug