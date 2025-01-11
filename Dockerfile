# Imaginea de bază
FROM gcc:latest

# Setăm directorul de lucru
WORKDIR /usr/src/app

# Copiem fișierul sursă
COPY main.cpp .

# Compilăm fișierul
RUN g++ -o main main.cpp

# Setăm punctul de pornire
CMD ["./main"]
