<?php


/**
  * Example of an API call.
  */

function MODULE_get_weather_forecast($lat = '51.0962', $lon = '4.2279') {
  $api_key = 'security_through_omittance';
  $json = file_get_contents("http://api.openweathermap.org/data/2.5/weather?lat={$lat}&lon={$lon}&APPID={$api_key}");        
  $parsed_json = json_decode($json, TRUE); 

  // Take the average daily temperature, so we don't need to hammer the weather API.
  $average_temp = $parsed_json['main']['temp_max'] - $parsed_json['main']['temp_min'] ;
  $weather_description = $parsed_json['weather'][0]['description'];
  $weather_source_icon = substr($parsed_json['weather'][0]['icon'], 0, 2);

  $current_condition = array(
    '01' => t('Clear'),
    '02' => t('Lightly cloudy'),
    '03' => t('Lightly cloudy'),
    '04' => t('Cloudy'),
    '09' => t('Light rain'),
    '10' => t('Rain'),
    '11' => t('Stormy'),
    '13' => t('Snow'),
    '50' => t('Mist')
  );

  return $weather = array(
    'average_temp' => (int) round($average_temp),
    'icon' => $current_condition[$weather_source_icon],
  );
}