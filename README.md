# Islandora Themekey

Provides [Themekey](https://dupal.org/project/themekey) theme-switching rules for Islandora objects. In a nutshell, this module will change your site's theme based on attributes of Islandora objects. Currently, only rules based on Islandora object collection membership are supported. You can use the 'drupal:path' property to switch the theme when viewing a particular Islandora object, such as a collection.

Note that Islandora objects that are in multiple collections may not trigger a rule, since only the first collection that an object is in is inspected. This limitation will be resolved in a future version of the module.

## Requirements

* [Islandora](https://github.com/Islandora/islandora)
* [Themekey](https://dupal.org/project/themekey)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Usage

Install and configure. To create a rule based on Islandora collection membership, go to Admin > Configuration > User Interface > Themekey. Select 'islandora:ismemberofcollection' in the rule properties list, select either the '=' or '!' operator, enter the PID of the collection you want to change the theme for, and save.

## Troubleshooting/issues/feedback

Feedback and use cases for Islandora-specific rules are welcome.

* [Islandora Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora)
* [Islandora Dev Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora-dev)

