# Islandora Themekey

Provides [Themekey](https://dupal.org/project/themekey) theme-switching rules for Islandora objects. In a nutshell, this module will change your site's theme based on attributes of Islandora objects. Currently, only rules based on Islandora object collection membership are supported. Supports membership in multiple collections. Additional use cases are welcome.

## Requirements

* [Islandora](https://github.com/Islandora/islandora)
* [Themekey](https://dupal.org/project/themekey)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Usage

Install and configure. To create a rule based on Islandora collection membership, go to Admin > Configuration > User Interface > Themekey and select 'islandora:ismemberofcollection' in the rule properties list, and then select either the '\*' or '!\*' operator.

Use the 'drupal:path' property to switch the theme when viewing a specific Islandora object, such as a collection.

## Troubleshooting/issues/feedback

Feedback and use cases for Islandora-specific theme-switching rules are welcome.

* [Islandora Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora)
* [Islandora Dev Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora-dev)

