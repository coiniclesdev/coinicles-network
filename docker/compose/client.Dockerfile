FROM compose-base:latest

COPY ./docker/compose/client.ini /root/.coiniclesnet/coiniclesnet.ini

CMD ["/coiniclesnet"]
EXPOSE 1090/udp 1190/tcp
