#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char cropType[50];
    char growthStage[50];
    float expectedYield;
} Crop;

typedef struct {
    float temperature;
    float rainfall;
    float windSpeed;
} WeatherForecast;

typedef struct {
    char name[50];
    int operationalStatus;
} Equipment;

typedef struct {
    float soilNutrients;
    float pHLevel;
    int pestActivity;
} Sensor;

typedef struct {
    float gpsLatitude;
    float gpsLongitude;
    Crop *cropData;
    WeatherForecast *weatherData;
    Equipment **equipmentArray;
    Sensor *sensorArray;
    int numEquipment;
    int numSensors;
} Field;

Field *initializeField(float latitude, float longitude, int numEquip, int numSensors) {
    Field *field = (Field *)malloc(sizeof(Field));
    field->gpsLatitude = latitude;
    field->gpsLongitude = longitude;
    field->cropData = (Crop *)malloc(sizeof(Crop));
    field->weatherData = (WeatherForecast *)malloc(sizeof(WeatherForecast));
    field->equipmentArray = (Equipment **)malloc(numEquip * sizeof(Equipment *));
    for (int i = 0; i < numEquip; i++) {
        field->equipmentArray[i] = (Equipment *)malloc(sizeof(Equipment));
    }
    field->sensorArray = (Sensor *)malloc(numSensors * sizeof(Sensor));
    field->numEquipment = numEquip;
    field->numSensors = numSensors;
    return field;
}

void freeField(Field *field) {
    free(field->cropData);
    free(field->weatherData);
    for (int i = 0; i < field->numEquipment; i++) {
        free(field->equipmentArray[i]);
    }
    free(field->equipmentArray);
    free(field->sensorArray);
    free(field);
}

int main() {
    Field *field = initializeField(12.34, 56.78, 3, 2);
    freeField(field);
    return 0;
}
