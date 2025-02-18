FROM gcc:latest
WORKDIR /usr/src/app
COPY main.cpp .
RUN g++ -o main main.cpp
CMD ["./main"]
