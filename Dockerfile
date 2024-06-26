# syntax=docker/dockerfile:1
FROM ghcr.io/fil-language/building:latest as build
COPY . /filc
WORKDIR /filc
RUN cmake -B ./build -DCMAKE_BUILD_TYPE=Release && \
    cmake --build ./build --target filc

FROM alpine:latest
COPY --from=build /filc/build/filc /bin/filc