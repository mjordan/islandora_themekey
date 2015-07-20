# Islandora Themekey

Provides [ThemeKey](https://www.drupal.org/project/themekey) theme-switching rules for Islandora objects. In a nutshell, this module will change your site's theme based on attributes of Islandora objects. Rules based on the following attributes of Islandora objects are supported:

* collection membership (using equals, not equals, contains, and not contains operators)
* namespace (using equals, not equals, contains, not contains, regular expression, and not regular expression operators)
* content model (using equals, not equals, contains, and not contains operators)

Be aware that if an object is a member of multiple collections that are used in ThemeKey rules, the first rule in the theme switching chain will apply.

> Note that on July 19, 2015, I changed the condition name of ismemberofcollection to is_member_of_collection to improve readibility in the long list of conditions. If you update the module from a version installed prior to that date, you will also need to update any rules you created prior to the change so that they use the new condition name (is_member_of_collection). This change does not affect sites that install the module for the first time afte July 19. I apologize for this backward compatibility breaking change but now that Islandora ThemeKey supports multiple conditions, I thought it was worth making their names more readable before we add any more. If you update the module, be sure to clear your Drupal cache, e.g., `drush cc all`.


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
5. choose the theme you want to be active if the property is true

Use the 'drupal:path' property to switch the theme when viewing a specific Islandora object, such as a collection.

## Troubleshooting/issues/feedback

Feedback and use cases for Islandora-specific theme-switching rules are welcome.

* [Islandora Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora)
* [Islandora Dev Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora-dev)

