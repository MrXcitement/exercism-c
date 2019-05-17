# Makefile --- manager the exercism-c docker container
# Mike Barker <mike@thebarkers.com>
# May 17th, 2019

servicename ?= exercism

.PHONY: all up shell stop down
all: up

up:
	mkdir -p $(CURDIR)/.config/exercism
	docker-compose up -d

shell:
	docker-compose exec $(servicename) bash --login

start:
	docker-compose start

stop:
	docker-compose stop

down:
	docker-compose down
