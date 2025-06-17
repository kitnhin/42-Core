DOCKER_COMPOSE = ./srcs/docker-compose.yml

all: build up

build:
	docker compose -f $(DOCKER_COMPOSE) build

up:
	docker compose -f $(DOCKER_COMPOSE) up -d

down:
	docker compose -f $(DOCKER_COMPOSE) down

clean:
	docker compose -f $(DOCKER_COMPOSE) down --volumes

fclean: clean
	docker compose -f $(DOCKER_COMPOSE) down --rmi all --volumes

build-nc:
	docker compose -f $(DOCKER_COMPOSE) build --no-cache

rvol:
	sudo rm -rf /home/ethan/data/wordpress
	sudo rm -rf /home/ethan/data/mariadb
	mkdir -p /home/ethan/data/wordpress
	mkdir -p /home/ethan/data/mariadb

upnc: build-nc up

renc: fclean build-nc up

re: fclean build up

.PHONY: all build up down clean fclean build-nc upnc renc re