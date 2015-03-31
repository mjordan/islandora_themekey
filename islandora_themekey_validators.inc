<?php

/**
 * @file
 * Validation functions for Islandora Themekey.
 */

/**
 * Validates a Theme Switching Rule.
 */
function islandora_themekey_validator_ismemberofcollection($rule) {
  $errors = array();

  switch ($rule['operator']) {
    case '=':
    case '!':
    case '<':
    case '>':
    case '>=':
    case '~':
    case '!~':
      $errors['operator'] = t('The only valid operators are "*", and "!*"');
      break;

    case '*':
    case '!*':
      if (!preg_match('/:/', $rule['value'])) {
        $errors['value'] = t('Collection PID must contain a :');
      }
      break;

    default:
      if (!preg_match('/:/', $rule['value'])) {
        $errors['value'] = t('Collection PID must contain a :');
      }
      break;
  }

  return $errors;
}
