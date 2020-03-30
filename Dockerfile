FROM ubuntu
LABEL maintainer = "Mark Platonov"
RUN apt-get update && apt-get install -y gcc
WORKDIR /home
COPY /code .
