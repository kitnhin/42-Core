DOCKER-COMPOSE = ./docker-compose.yml

all: build up

up:
	docker-compose -f $(DOCKER-COMPOSE) up -d --build

down:
	docker-compose -f $(DOCKER-COMPOSE) down

fclean:
	docker-compose down --rmi all --volumes

re: fclean up