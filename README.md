# Contribution guidelines

Thank you for considering contributing to our R-Type project!

These guidelines are meant for new contributors, regardless of their level of proficiency; following them allows the maintainers our R-Type project to more effectively evaluate your contribution, and provide prompt feedback to you. Additionally, by following these guidelines you clearly communicate that you respect the time and effort that the people developing R-Type project put into managing the project.

#### Langage: English

All interactions should be in English, to allow everyone to understand and participate.

### Description of the project

The goal is to implement a multithreaded server and a graphical client for a well-known legacy video game
called R-Type in C++.

## Table of Contents

- [How to launch the project](#how-to-launch-the-project)
  - [Supported OS](#supported-os)
  - [Requirements](#requirements)
  - [Dependencies](#dependencies)
  - [Execution](#execution)
- [Documentation](#documentation)
- [How to report a bug](#how-to-report-a-bug)
- [How to suggest a feature or enhancement](#how-to-suggest-a-feature-or-enhancement)
- [Where can I ask for help?](#where-can-i-ask-for-help)
- [Coding style](#coding-style)
- [Commit format](#commit-format)
- [Labels](#labels)
- [Branches](#branches)
  - [Namming](#branches-namming)
- [Pull Requests](#pull-requests)
  - [Namming](#pull-requests-namming)
  - [Process](#pull-requests-process)
    - [Code review](#pull-requests-process-code-review)
    - [PR Stability](#pull-requests-process-PR-stability)
    - [Miscellaneous](#pull-requests-process-miscellaneous)
- [Milestone](#milestones)
  - [Namming](#milestones-namming)
- [Testing Policies](#testing-policies)
  - [Unit tests](#testing-policies-unit-tests)
  - [Functional tests](#testing-policies-functional-tests)
  - [CI / CD](#testing-policies-CI-CD)
- [Contributors](#contributors)

## How to launch the project

### Supported OS
- Linux
- Windows
- MacOS

### Requirements
- [C++17](https://en.cppreference.com/w/cpp/17)
- [CMake](https://cmake.org/)

### Dependencies

- [Criterion](https://github.com/Snaipe/Criterion)
- [Ftest](https://github.com/Atomot/ftest)
- [Doxygen](https://github.com/doxygen/doxygen)

### Execution

```bash
cmake -B build/
make -C build/
./r-type_server [port]
./r-type_client
```

##### I you wish to execute the server within a Docker container:

- Make sure you have Docker installed
- Build the r-type-server image within your directory
```bash
docker build -t r-type-server-image .
```
- Run the server
```bash
docker run r-type-server-image
```

## Documentation

There is a Doxygen documentation in the project. You can generate it with the following command:

```bash
cmake -B build/
make doxygen -C build/
```
Then open the file `docs/html/index.html` in your browser.

## How to report a bug

If you find a bug, you can open an issue on the repository. You need to describe the bug and how to reproduce it. You can maybe find a template for the issue.

## How to suggest a feature or enhancement

If you want to suggest a feature or enhancement, you can open an issue on the repository. You need to describe the feature or enhancement. You can maybe find a template for the issue.

## Where can I ask for help?

You can ask for help to [developpers team](#Contributors) or on the issue/PR.

(When interacting with us, please be human being)

## Coding style

We use SonarLint as coding style.

You can use the SonarLint plugin for your IDE.

## Commit format

In the project, we use [Angular Commit Convention](https://www.conventionalcommits.org/en/v1.0.0-beta.4/)

## Labels

Each labels must be the type of the Issue.
/!\ It's not the work functional type but the type of the issue. /!\

## Branch

### Namming

Branch should have an automatic namming due to branch creation via issues. But if you create a branch from nothing you must use [Angular Commit Convention](https://www.conventionalcommits.org/en/v1.0.0-beta.4/).

## Pull Requests (PR)

### Namming

If you create a PR, you must use [Angular Commit Convention](https://www.conventionalcommits.org/en/v1.0.0-beta.4/).

(In most of the case, you can reuse issue name)

### Process

#### Code review

For each PR we'll have a code review, the PR must be approved by 2 developper of the [developpers team](#Contributors).

#### PR Stability

Look at the [**Testing Policies**](#testing-policies)

#### Miscellaneous

Don't add to R-Type github project except if the PR doesn't have issue (it shouldn't be the case but why not).

Don't add to any Milestone of the project. If you doubt, ask to [developpers team](#Contributors).

## Milestone

Milestone are used to organize the project. Each milestone must have a description and a due date. A milestone should be linked to an issue or a PR. A milestone should be linked to a set of functionnalities that makes the project works or a set of functionnalities that makes the project coherent.

### Namming

If you create a milestone, you must use [Angular Commit Convention](https://www.conventionalcommits.org/en/v1.0.0-beta.4/).

## Testing Policies

### Unit tests

Please do unit tests with [Criterion](https://github.com/Snaipe/Criterion) if you can. We don't have a coverage goal for the moment.

### Functional tests

We don't force you to do functional tests but if you can do it, it's better. We use [Ftest](https://github.com/Atomot/ftest) for functional tests.

### CI / CD

We have a really basic CI at the moment.

## Contributors

 - [Andréas Le Tanter](https://github.com/AndreasLETANTER)
 - [Louis Barreteau](https://github.com/lbarreteau)
 - [Hugo Noury](https://github.com/HugoN1)
 - [Hugo Guiheneuf](https://github.com/Hugoguiheneuf)
 - [Eliot Baratte](https://github.com/eliotbaratte)
