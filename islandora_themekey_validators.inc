<?php

/**
 * @file
 * Validation functions for Islandora Themekey.
 */

/**
 * Validates the ismemberofcollection Theme Switching Rule.
 */
function islandora_themekey_validator_ismemberofcollection($rule) {
  $errors = array();

  switch ($rule['operator']) {
    case '=':
    case '!':
    case '*':
    case '!*':
      if (!preg_match('/:/', $rule['value'])) {
        $errors['value'] = t('Collection PID must contain a :');
      }
      break;

    default:
      $errors['operator'] = t('The only valid operators are "=", "!", "*", and "!*"');
      break;
  }

  return $errors;
}

/**
 * Validates the hasnamespace Theme Switching Rule.
 */
function islandora_themekey_validator_hasnamespace($rule) {
  $errors = array();

  switch ($rule['operator']) {
    case '=':
    case '!':
    case '*':
    case '!*':
    case '~':
    case '!~':
      if (!strlen($rule['value'])) {
        $errors['value'] = t('Namespace must be longer than 0 characters');
      }
      break;

    default:
      $errors['operator'] = t('The only valid operators are "=", "!", "*", "!*", "~", and "!~"');
      break;
  }

  return $errors;
}
