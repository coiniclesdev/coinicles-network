ARG bootstrap="https://i2p.rocks/i2procks.signed"
FROM alpine:edge as builder

RUN apk update && \
    apk add build-base cmake git libcap-dev libcap-static libuv-dev libuv-static curl ninja bash binutils-gold curl-dev

WORKDIR /src/
COPY . /src/

RUN make NINJA=ninja STATIC_LINK=ON BUILD_TYPE=Release DOWNLOAD_SODIUM=ON
RUN ./coiniclesnet-bootstrap ${bootstrap}

FROM alpine:latest

COPY coiniclesnet-docker.ini /root/.coiniclesnet/coiniclesnet.ini
COPY --from=builder /src/build/daemon/coiniclesnet .
COPY --from=builder /root/.coiniclesnet/bootstrap.signed /root/.coiniclesnet/

CMD ["./coiniclesnet"]
EXPOSE 1090/udp 1190/tcp
