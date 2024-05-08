# Generator of quotes from an API

## Description
This repo contains a prog that generates quotes from an API.

## lib
curl : sudo apt-get install libcurl4-openssl-dev
json : sudo apt-get install libcjson-dev

## Compile
gcc -o main main.c api.c -lcurl -lcjson