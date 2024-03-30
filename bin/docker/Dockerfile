# syntax=docker/dockerfile:1
FROM ghcr.io/fil-language/building:latest as build
RUN git clone https://github.com/Fil-Language/filc && \
    cd /filc && \
    cmake -B ./build -DCMAKE_BUILD_TYPE=Release && \
    cmake --build ./build

FROM alpine:latest
COPY --from=build /filc/build/filc /bin/filc