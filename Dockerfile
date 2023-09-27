# Use Ubuntu base image
FROM ubuntu:latest

# Install dependencies
COPY requirements.txt /tmp/requirements.txt
RUN apt-get update && \
    apt-get install -y $(cat /tmp/requirements.txt) && \
    rm /tmp/requirements.txt

# Install Criterion
RUN wget https://github.com/Snaipe/Criterion/releases/download/v2.4.1/criterion-2.4.1-linux-x86_64.tar.xz && \
	tar xvf criterion-2.4.1-linux-x86_64.tar.xz && \
	cp -r /criterion-2.4.1/lib/* /usr/lib/ && \
	cp -r /criterion-2.4.1/include/* /usr/include/ && \
	rm criterion-2.4.1-linux-x86_64.tar.xz

# Set the container
WORKDIR /r-type
COPY . /r-type

# Build the project using CMake
RUN mkdir build
RUN cmake -B build
RUN make server -C build

# Run the server
CMD ["./r-type_server", "8080"]
