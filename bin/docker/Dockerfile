# syntax=docker/dockerfile:1
FROM ghcr.io/fil-language/building:latest as build
COPY .. /filc
RUN cmake -B /filc/build -DCMAKE_BUILD_TYPE=Release && \
    cmake --build /filc/build

FROM alpine:latest
COPY --from=build /filc/build/filc /bin/filc