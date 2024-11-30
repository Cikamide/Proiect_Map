FROM gcc:latest
WORKDIR /usr/src/myapp
COPY main.cpp .
RUN gcc -o main main.cpp -lstdc++
CMD [ "./main" ]