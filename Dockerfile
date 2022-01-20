FROM ubuntu:18.04

MAINTAINER DimaGalkin

EXPOSE 80

COPY * /tmp/Kernel/

RUN  apt-get update && apt-get install xorriso -y &&  apt-get install build-essential -y &&  apt-get install qemu-system -y

VOULME ["~"]

CMD
