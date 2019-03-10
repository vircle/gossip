FROM ubuntu:16.04

RUN apt-get update
RUN apt-get install -y wget pwgen

ARG RPC_USER
ARG RPC_PASSWORD
ENV RPC_USER ${RPC_USER:-gossip}
# Create a random password if the user doesn't set one
ENV RANDOM_PASS `pwgen -Bs1 12`
ENV RPC_PASSWORD ${RPC_PASSWORD:-$RANDOM_PASS}

# Build the project
RUN wget https://github.com/g0ssipcoin/GossipCoinCore/releases/download/v2.0.0.0/gossip-2.0.0-x86_64-linux-gnu.tar.gz -O gossip-2.0.0.tar.gz
RUN tar -xvf gossip-2.0.0.tar.gz
RUN mkdir -p /root/.gossip/
RUN echo "rpcuser=$RPC_USER\nrpcpassword=$RPC_PASSWORD" > /root/.gossip/gossip.conf

EXPOSE 8332 8333 18332 18333

WORKDIR /gossip-2.0.0/bin
CMD ["/gossip-2.0.0/bin/gossipd"]

