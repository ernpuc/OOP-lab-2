# Objektinio programavimo pirmas laboratorinis darbas

### v0.4
- Sukurtas naujų failų generatorius
- Spausdinant rezultatus į failus studentai yra surūšiuojami pagal galutinį pažymį (jei paž. mažesnis nei 5, studentas priskiriamas "vargšams", o jei daugiau, "kietiems")
- Programos veikimo metu skaičiuojama, kiek užtruko failo generavimas, failo skaitymas, studentų rūšiavimas, išvedimas į failus, taip pat visas programos vykdymo laikas
- Pakoreguota programos veikimo logika, dialogas su vartotoju

### v0.3
- Programoje naudojamas išimčių valdymas

### v0.2
- Duomenys prieš išvedimą yra surikiuojami pagal studentų vardus, arba, jei jie vienodi, pavardes
- Galima rinktis duomenų įvedimą iš failo
- Duomenis skaitant iš failo, rezultatai yra išvedami į "rezultatai.txt"

### v0.1
- Pagal formulę **_Galutinis = 0.4 * vidurkis + 0.6 * egzaminas_** apskaičiuojami studentų galutiniai pažymiai
- Galima pasirinkti ar norima galutinį pažymį skaičiuoti su vidurkiu, su mediana, ar su abiejais
- Galima pasirinkti ar duomenys suvedami ranka, ar sugeneruojami atsitiktinai

## Programos veikimo greičio analizė (kuriami ir skaitomi įrašai su penkiais ND pažymiais)

|                        Įrašų skaičius: |           1000 |          10000 |         100000 |        1000000 |       10000000 |
|----------------------------------------|----------------|----------------|----------------|----------------|----------------|
| Failo kūrimas                          |     0.0018904s |     0.0154956s |       0.12917s |       1.28456s |       12.8644s |




|                        Įrašų skaičius: |           1000 |          10000 |         100000 |        1000000 |       10000000 |
|----------------------------------------|----------------|----------------|----------------|----------------|----------------|
| Failo nuskaitymas                      |      0.003755s |      0.021145s |      0.210719s |      2.024652s |     18.976490s |
| Duomenų rūšiavimas pagal pažymį        |      0.000117s |      0.000826s |      0.010425s |      0.100134s |      1.086924s |
| Duomenų skirstymas                     |      0.000070s |      0.000503s |      0.008995s |      0.130134s |      1.390153s |
| Duomenų rūšiavimas pagal pavardes      |      0.000226s |      0.002772s |      0.044775s |      0.476623s |      5.207225s |
| Rezultatų spausdinimas į "vargsai.txt" |      0.000767s |      0.004737s |      0.049646s |      0.378064s |      3.689593s |
| Rezultatų spausdinimas į "kieti.txt"   |      0.000642s |      0.005030s |      0.042048s |      0.455202s |      4.393126s |
| **Visas programos vykdymo laikas:**    |  **0.008422s** |  **0.038534s** |  **0.375240s** |  **3.639630s** | **35.418379s** |





















