
# GCC support can be specified at major, minor, or micro version
# (e.g. 8, 8.2 or 8.2.0).
# See https://hub.docker.com/r/library/gcc/ for all supported GCC
# tags from Docker Hub.
# See https://docs.docker.com/samples/library/gcc/ for more on how to use this image
FROM gcc:4.9

# These commands copy your files into the specified directory in the image
# and set that as the working location
COPY . /usr/src/myapp
WORKDIR /usr/src/tarea3

# This command compiles your app using GCC, adjust for your source code
RUN g++ -o tarea3 ppal.cpp

# This command runs your application, comment out this line to compile only
CMD ["./tarea3"]

LABEL Name=tarea3 Version=0.0.1
