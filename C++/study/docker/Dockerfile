FROM node:10

# App directory
WORKDIR /usr/src/App

COPY package.json ./ 

RUN npm install

# copy the whole file at current directory to workingdir
COPY . .

# Use this port on Docker
EXPOSE 8080

CMD ("node". "index.js")