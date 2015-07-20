# Islandora Themekey

Provides [Themekey](https://www.drupal.org/project/themekey) theme-switching rules for Islandora objects. In a nutshell, this module will change your site's theme based on attributes of Islandora objects. Rules based on the following attributes of Islandora objects are supported:

* collection membership (using equals, not equals, contains, and not contains operators)
* namespace (using equals, not equals, contains, not contains, regular expression, and not regular expression operators)
* content model (using equals, not equals, contains, and not contains operators)

Be aware that rules using collection membership [do not work with paged content](https://github.com/mjordan/islandora_themekey/issues/4). Also, if an object is a member of multiple collections that are used in ThemeKey rules, the first rule in the theme switching chain will apply.

Note that on July 19, 2015, I changed the condition name of ismemberofcollection to is_member_of_collection to improve readibility in the long list of conditions. You will need to update any rules you created prior to the change to use the new condition name (is_member_of_collection). I apologize for this backward compatibility breaking change but now that Islandora ThemeKey supports multiple conditions, I thought it was worth making their names more readable.


## Requirements

* [Islandora](https://github.com/Islandora/islandora)
* [Themekey](https://dupal.org/project/themekey)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Usage

To create a theme switching rule,

1. go to Admin > Configuration > User Interface > Themekey
2. select one of the properties starting with 'islandora' in the rule properties list
3. select an operator
4. enter the PID of the collection or content model, or the namespace

Use the 'drupal:path' property to switch the theme when viewing a specific Islandora object, such as a collection.

## Troubleshooting/issues/feedback

Feedback and use cases for Islandora-specific theme-switching rules are welcome.

* [Islandora Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora)
* [Islandora Dev Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora-dev)

