username ?= mrbarker
imagename ?= exercism-c
tag ?= 0.1.2

all: doker-run

docker-run:
	mkdir -p $(CURDIR)/.config/exercism
	docker run \
		-dit \
		-v $(CURDIR)/.config/exercism:/root/.config/exercism \
		-v $(CURDIR):/workspace \
		--name $(imagename) \
		$(username)/$(imagename):$(tag)

docker-exec:
	docker exec -it $(imagename) bash --login

docker-stop:
	docker stop $(imagename)

docker-kill:
	docker kill $(imagename)

docker-rm:
	docker rm $(imagename)
