FROM compose-base:latest

ENV COINICLESNET_NETID=docker

COPY ./docker/compose/bootstrap.ini /root/.coiniclesnet/coiniclesnet.ini

CMD ["/coiniclesnet"]
EXPOSE 1090/udp 1190/tcp
