// Description
//
// We want to find the closest airborne aeroplane to any given position in North America or Europe. To assist in this we can use an API which will give us the data on all currently airborne commercial aeroplanes in these regions.
//
// OpenSky's Network API can return to us all the data we need in a JSON format.
//
// https://opensky-network.org/api/states/all
//
// From this we can find the positions of all the planes and compare them to our given position.
//
// Use the basic Euclidean distance in your calculation.
// Input
//
// A location in latitude and longitude, cardinal direction optional
//
// An API call for the live data on all aeroplanes
// Output
//
// The output should include the following details on the closest airborne aeroplane:
//
// Geodesic distance
// Callsign
// Lattitude and Longitude
// Geometric Altitude
// Country of origin
// ICAO24 ID
//
// Challenge Inputs
//
// Eifel Tower:
//
// 48.8584 N
// 2.2945 E
//
// John F. Kennedy Airport:
//
// 40.6413 N
// 73.7781 W
//
// Bonus
//
// Replace your distance function with the geodesic distance formula, which is more accurate on the Earth's surface.

#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <curl/curl.h>

using json = nlohmann::json;

void get_geodesic_distance();
void get_callsign();
void get_lattitude_and_longitutde();
void get_country_of_origin();
void get_ICA024ID();

namespace
{
    std::size_t callback(
        const char* IN,
        std::size_t size,
        std::size_t num,
        std::string* out)
    {
        const std::size_t TOTAL_BYTES(size * num);
        out->append(IN, TOTAL_BYTES);
        return TOTAL_BYTES;
    }
}

int main()
{
    const std::string AEROPLANE_DATA_URL("https://opensky-network.org/api/states/all");

    CURL* curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, AEROPLANE_DATA_URL.c_str());
    curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 20);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    int http_code(0);
    std::unique_ptr<std::string> http_data(new std::string());

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, http_data.get());

    curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    curl_easy_cleanup(curl);

    return 0;
}
