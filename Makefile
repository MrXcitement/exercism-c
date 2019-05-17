username ?= mrbarker
imagename ?= exercism-c
tag ?= 0.1.1

all: run

run:
	mkdir -p $(CURDIR)/.config/exercism
	docker run \
		-dit \
		-v $(HOME)/.gitconfig:/root/.gitconfig \
		-v $(CURDIR)/.config/exercism:/root/.config/exercism \
		-v $(CURDIR):/root/exercism \
		--privileged=true \
		--name $(imagename) \
		$(username)/$(imagename):$(tag)

shell:
	docker exec -it $(imagename) bash --login

stop:
	docker stop $(imagename)

kill:
	docker kill $(imagename)

rm:
	docker rm $(imagename)
