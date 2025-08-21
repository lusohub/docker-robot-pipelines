FROM gcc:12

WORKDIR /app

COPY robot.cpp robot.h CMakeLists.txt ./

RUN apt-get update && apt-get install -y cmake && \
    cmake . && make robot && \
    rm -rf /var/lib/apt/lists/*

ENTRYPOINT ["./robot"]