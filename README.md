# Islandora Themekey

Provides [Themekey](https://www.drupal.org/project/themekey) theme-switching rules for Islandora objects. In a nutshell, this module will change your site's theme based on attributes of Islandora objects. Rules based on the following attributes of Islandora objects are supported:

* collection membership (using equals, not equals, contains, and not contains operators)
* namespace (using equals, not equals, contains, not contains, regular expression, and not regular expression operators)

Be aware that rules using collection membership [do not work with paged content](https://github.com/mjordan/islandora_themekey/issues/4).

## Requirements

* [Islandora](https://github.com/Islandora/islandora)
* [Themekey](https://dupal.org/project/themekey)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Usage

Install and configure. To create a rule based on Islandora collection membership, go to Admin > Configuration > User Interface > Themekey and select one of the properties starting with 'islandora' in the rule properties list, and then select an operator.

Use the 'drupal:path' property to switch the theme when viewing a specific Islandora object, such as a collection.

## Troubleshooting/issues/feedback

Feedback and use cases for Islandora-specific theme-switching rules are welcome.

* [Islandora Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora)
* [Islandora Dev Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora-dev)

