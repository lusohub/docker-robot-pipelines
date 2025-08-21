# docker-robot-pipelines

Este código é um simulador de um robot diferencial (um robot com duas rodas independentes: robot móveis e aspiradores por exemplo).

## Executar

```
docker build -t robot-sim .
docker run -it robot-sim
```

```
L 2.0
R 2.0
Q // sair
```

## Correr Testes

```
sudo apt-get update
sudo apt-get install -y cmake g++ libgtest-dev
cd /usr/src/gtest
sudo cmake .
sudo make
sudo cp lib/*.a /usr/lib

cd /workspaces/docker-robot-pipelines
mkdir build
cd build
cmake ..
make

LD_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu ctest --output-on-failure
```