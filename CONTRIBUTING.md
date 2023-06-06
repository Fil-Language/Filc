# Contributing

First of all, thanks for taking time to contribute! ❤️

Anyone is welcome to contribute to this project. And if you not have time to contribute, don't worry. You can also :

- Star the project ⭐
- Mention the project to your friends/colleagues 🗣
- Sponsor the project 💸

## Code of conduct

The code of conduct is described in [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md).

## Issues

Filc use GitHub issues to track issues.

Before opening a new one, check that there is not an existing [issue](/issues) answering to your problem.

Then, you can open a [new issue](/issues/new/choose) and choose the corresponding template. Please ensure your
description is clear and has sufficient details to be able to reproduce the issue.

## Getting started

Here is a small checklist:

- Discuss the changes you want to make first
- Create a fork of this repository
- Checkout a new branch on top of `develop` branch
- Make all your changes
- Submit a pull request

## Submitting pull requests

Before we can merge your pull request, here are some guidelines you need to follow.

These guidelines help keeping the code clean, stable and easier to review.

**Principles**

- No dead code: If you create a function, it's to use it
- All functions, class, types should be as strictly as possible
- Comment, sometimes it's painful to comment, but it helps you and us to understand the code and improve it

**Conventions**

C++ conventions and rules are all listed in `.clang-tidy` and `.clang-format` files. Modern IDEs all supports
formatting from these files. If you not use an IDE, please call `clang-tidy` as often as possible to keep your code
clear.

**Tests**

We tried to keep our test coverage as high as possible. It means that everything *MUST* be tested.

If you submit a bug fix, add a test case reproducing the bug. If it's a new feature, add tests covering all code paths.

For testing we use googletest with cmake. Just use ctest to run them.

**License**

By contributing to Filc, you agree that your contributions will be licensed under the [LICENSE](LICENSE.md) file in the
root directory of this source tree.

**Pull request**

When submitting your pull request please follow the provided template. Our team will review your code as soon as
possible.

## Security

You can read more about how to report security issues in our [Security Policy](SECURITY.md).