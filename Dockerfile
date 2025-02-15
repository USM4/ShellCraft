FROM ubuntu:latest

# Avoid prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    make \
    wget \
    libreadline-dev \
    && rm -rf /var/lib/apt/lists/*

# directory structure for the readline installation
RUN mkdir -p /goinfre/root/.brew/opt/readline/lib && \
    mkdir -p /goinfre/root/.brew/opt/readline/include

# Copy system readline to our custom location
RUN cp -r /usr/include/readline /goinfre/root/.brew/opt/readline/include/ && \
    cp /usr/lib/x86_64-linux-gnu/libreadline.so* /goinfre/root/.brew/opt/readline/lib/ && \
    cp /usr/lib/x86_64-linux-gnu/libhistory.so* /goinfre/root/.brew/opt/readline/lib/

# Set working directory
WORKDIR /app

# Copying the  project files
COPY . .

# Set environment variables
ENV CC=gcc
ENV USER=root
ENV CFLAGS="-Wall -Werror -Wextra -fcommon"
ENV LDFLAGS="-Wl,--allow-multiple-definition"
ENV LD_LIBRARY_PATH="/goinfre/root/.brew/opt/readline/lib:${LD_LIBRARY_PATH}"

# make and execute inside the script 
CMD ["./install.sh"]