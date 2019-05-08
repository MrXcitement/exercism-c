# Exercism 'C' Track
An Exercism 'C' track project. 

## Overview
This project uses the docker exercism c image to create a container that can be
used to work through the 'c' track exercises.

## Usage

To run the exercism 'c' container

```
$ make docker-run
```

To 'exec' a login shell in the container

```
$ make docker-exec
```

To stop the container

```
$ make docker-stop
```

To kill the container, if it can't be stopped

```
$ make docker-kill
```

To rm the container

```
$ make docker-rm
```

## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code of
conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available,
see the [tags on this repository](https://github.com/mrxcitement/docker-exercism-base/tags). 

## Authors

* **Mike Barker** - *Initial work* - [MrXcitement](https://github.com/mrxcitement)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

