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
