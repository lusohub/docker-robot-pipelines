FROM gcc:12

WORKDIR /app

RUN apt-get update && apt-get install -y cmake libgtest-dev && \
    cd /usr/src/gtest && cmake . && make && cp lib/*.a /usr/lib && \
    rm -rf /var/lib/apt/lists/*

COPY . .

RUN cmake . && make

ENTRYPOINT ["./robot"]