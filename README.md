# Objektinio programavimo antras laboratorinis darbas

## Naudojimosi instrukcija

- Norint įdiegti programą, paleisti RUNMEE.bat failą
- Paleidus .exe failą sekti konsolėje esančias instrukcijas (programos pradžioje pasirinktos komandos lems programos vykdymo ypatumus)

## Programos versijos

### v1.5
- Studento klasei sukurta abstrakti bazinė žmogaus klasė
- 
### v1.2
- Pridėti copy ir move konstruktoriai bei priskyrimo operatoriai

### v1.1
- Programa realizuota su klasėmmis

#### Programos veikimo greičio su studentų klase (v1.1.) ir struktūra (v1.0) analizė

v1.1

| Irasu skaicius:                         |      1000000   |     10000000   |
|-----------------------------------------|----------------|----------------|
| Failo nuskaitymas                       |     2.489588s  |    25.402104s  |
| Duomenu rusiavimas pagal pazymi         |     0.073588s  |     0.797581s  |
| Duomenu skirstymas                      |     0.157918s  |     1.504101s  |
| Duomenu rusiavimas pagal pavardes       |     0.973850s  |    11.752730s  |
| Rezultatu spausdinimas i vargsai.txt    |     0.386475s  |     3.906130s  |
| Rezultatu spausdinimas i kieti.txt      |     0.402160s  |     4.160941s  |
| Visas programos vykdymo laikas:         |     4.777175s  |    50.263985s  |


v1.0

| Irasu skaicius:                         |      1000000   |     10000000   |
|-----------------------------------------|----------------|----------------|
| Failo nuskaitymas                       |     1.935183s  |    19.500268s  |
| Duomenu rusiavimas pagal pazymi         |     0.072969s  |     0.802412s  |
| Duomenu skirstymas                      |     0.129385s  |     1.373299s  |
| Duomenu rusiavimas pagal pavardes       |     0.459012s  |     5.295557s  |
| Rezultatu spausdinimas i vargsai.txt    |     0.375047s  |     3.987322s  |
| Rezultatu spausdinimas i kieti.txt      |     0.394954s  |     3.947082s  |
| Visas programos vykdymo laikas:         |     3.605573s  |    37.451121s  |


#### Programos veikimo su skirtingais kompiliatoriaus optimizavimo lygiais analizė

-O1

| Irasu skaicius:                         |      1000000   |     10000000   |
|-----------------------------------------|----------------|----------------|
| Failo nuskaitymas                       |     2.596605s  |    26.404050s  |
| Duomenu rusiavimas pagal pazymi         |     0.105774s  |     1.050675s  |
| Duomenu skirstymas                      |     0.192379s  |     2.078027s  |
| Duomenu rusiavimas pagal pavardes       |     1.101112s  |    13.076459s  |
| Rezultatu spausdinimas i vargsai.txt    |     0.403579s  |     3.895943s  |
| Rezultatu spausdinimas i kieti.txt      |     0.433215s  |     4.195289s  |
| Visas programos vykdymo laikas:         |     5.085841s  |    53.189120s  |

-Vector.exe užima 88,5 KB 

-O2

| Irasu skaicius:                         |      1000000   |     10000000   |
|-----------------------------------------|----------------|----------------|
| Failo nuskaitymas                       |     2.489588s  |    25.402104s  |
| Duomenu rusiavimas pagal pazymi         |     0.073588s  |     0.797581s  |
| Duomenu skirstymas                      |     0.157918s  |     1.504101s  |
| Duomenu rusiavimas pagal pavardes       |     0.973850s  |    11.752730s  |
| Rezultatu spausdinimas i vargsai.txt    |     0.386475s  |     3.906130s  |
| Rezultatu spausdinimas i kieti.txt      |     0.402160s  |     4.160941s  |
| Visas programos vykdymo laikas:         |     4.777175s  |    50.263985s  |

-Vector.exe užima 105 KB

-Ox

| Irasu skaicius:                         |      1000000   |     10000000   |
|-----------------------------------------|----------------|----------------|
| Failo nuskaitymas                       |     2.538286s  |    26.688960s  |
| Duomenu rusiavimas pagal pazymi         |     0.074360s  |     0.788425s  |
| Duomenu skirstymas                      |     0.191593s  |     2.049583s  |
| Duomenu rusiavimas pagal pavardes       |     0.932755s  |    11.161583s  |
| Rezultatu spausdinimas i vargsai.txt    |     0.399271s  |     3.904824s  |
| Rezultatu spausdinimas i kieti.txt      |     0.429001s  |     4.163725s  |
| Visas programos vykdymo laikas:         |     4.793937s  |    51.256823s  |

-Vector.exe užima 107 KB

### v1.0
- Pateiktos trys skirtingos studentų skaidymo į "vargšus" ir "kietus" realizacijos

#### Studentų skirstymo į dvi kategorijas spartos analizė

- Pirma strategija - studentų skaidymas į du naujus konteinerius paliekant juos ir bendrame
- Antra strategija - studentų skaidymas į du konteinerius perkeliant vienus studentus iš bendro į naują konteinerį
- Trečia strategija - studentų skaidymas į du konteinerius kuriant naują konteinerį pagal surušiuotą bendrą konteinerį, o šį sumažinant iki reikiamo dydžio

##### Vektoriai

| Irasu skaicius:                         |         1000   |        10000   |       100000   |      1000000   |     10000000   |
|-----------------------------------------|----------------|----------------|----------------|----------------|----------------|
| Duomenu skirstymas (pirma strategija)   |     0.000226s  |     0.002328s  |     0.027280s  |     0.377596s  |     3.884641s  |
| Duomenu skirstymas (antra strategija)   |     0.000146s  |     0.001037s  |     0.013651s  |     0.159438s  |     1.435591s  |
| Duomenu skirstymas (trečia strategija)  |     0.000048s  |     0.000784s  |     0.012567s  |     0.126463s  |     1.480946s  |

##### Dekai

| Irasu skaicius:                         |         1000   |        10000   |       100000   |      1000000   |     10000000   |
|-----------------------------------------|----------------|----------------|----------------|----------------|----------------|
| Duomenu skirstymas (pirma strategija)   |     0.000575s  |     0.006810s  |     0.097976s  |     1.025728s  |    14.279388s  |
| Duomenu skirstymas (antra strategija)   |     0.000125s  |     0.001727s  |     0.029781s  |     0.348508s  |     3.847409s  |
| Duomenu skirstymas (trečia strategija)  |     0.000161s  |     0.001885s  |     0.036610s  |     0.437453s  |     5.057705s  |

##### Listai

| Irasu skaicius:                         |         1000   |        10000   |       100000   |      1000000   |     10000000   |
|-----------------------------------------|----------------|----------------|----------------|----------------|----------------|
| Duomenu skirstymas (pirma strategija)   |     0.000593s  |     0.008448s  |     0.126668s  |     1.290652s  |    16.339081s  |
| Duomenu skirstymas (antra strategija)   |     0.000135s  |     0.001842s  |     0.033589s  |     0.447529s  |     5.253159s  |
| Duomenu skirstymas (trečia strategija)  |     0.000192s  |     0.002959s  |     0.058770s  |     0.814941s  |     8.971007s  |

### v0.5
- Pateikta programos realizacija su skirtingų tipų konteineriais (vektoriai, dekai, listai)

#### Programos veikimo greičio su skirtingų tipų konteineriais analizė

Vektoriai:

| Įrašų skaičius:                         |         1000   |        10000   |       100000   |      1000000   |     10000000   |
|-----------------------------------------|----------------|----------------|----------------|----------------|----------------|
| Failo nuskaitymas                       |     0.002370s  |     0.018730s  |     0.186273s  |     1.869823s  |    19.175167s  |
| Duomenų rūšiavimas pagal pažymį         |     0.000126s  |     0.000825s  |     0.009354s  |     0.103563s  |     1.084800s  |
| Duomenų skirstymas                      |     0.000063s  |     0.000379s  |     0.007437s  |     0.135719s  |     1.716972s  |
| Duomenu rūšiavimas pagal pavardes       |     0.000235s  |     0.002923s  |     0.035559s  |     0.456397s  |     5.456266s  |
| **Visas matuotas laikas:**              |   **0.002794s**|   **0.022857s**|   **0.238623s**|   **2.565502s**|  **27.433205s**|

Dekai:

| Įrašų skaičius:                         |         1000   |        10000   |       100000   |      1000000   |     10000000   |
|-----------------------------------------|----------------|----------------|----------------|----------------|----------------|
| Failo nuskaitymas                       |     0.002403s  |     0.022267s  |     0.217057s  |     2.165592s  |    22.038994s  |
| Duomenų rūšiavimas pagal pažymį         |     0.000328s  |     0.002968s  |     0.053447s  |     0.890581s  |     9.711136s  |
| Duomenų skirstymas                      |     0.000115s  |     0.001730s  |     0.039442s  |     0.456210s  |     5.486380s  |
| Duomenų rūšiavimas pagal pavardes       |     0.000408s  |     0.006365s  |     0.088370s  |     1.477057s  |    19.354735s  |
| **Visas matuotas laikas:**              |   **0.003254s**|   **0.033330s**|   **0.398316s**|   **4.989440s**|  **56.591245s**|

Listai:

| Įrašų skaičius:                         |         1000   |        10000   |       100000   |      1000000   |     10000000   |
|-----------------------------------------|----------------|----------------|----------------|----------------|----------------|
| Failo nuskaitymas                       |     0.002491s  |     0.023129s  |     0.236863s  |     2.376549s  |    23.554708s  |
| Duomenų rūšiavimas pagal pažymį         |     0.000055s  |     0.001016s  |     0.021355s  |     0.541004s  |     8.323490s  |
| Duomenų skirstymas                      |     0.000155s  |     0.003449s  |     0.067021s  |     0.853937s  |     8.979197s  |
| Duomenų rūšiavimas pagal pavardes       |     0.000095s  |     0.001336s  |     0.022058s  |     0.461504s  |     7.019872s  |
| **Visas matavimo laikas:**              |   **0.002796s**|   **0.028930s**|   **0.347020s**|   **4.232994s**|  **47.877267s**|

#### Testavimo sistemos parametrai:
- CPU: AMD Ryzen 5 5600H
- RAM: 16 GB
- DISK: SSD

### v0.4
- Sukurtas naujų failų generatorius
- Spausdinant rezultatus į failus studentai yra surūšiuojami pagal galutinį pažymį (jei paž. mažesnis nei 5, studentas priskiriamas "vargšams", o jei daugiau, "kietiems")
- Programos veikimo metu skaičiuojama, kiek užtruko failo generavimas, failo skaitymas, studentų rūšiavimas, išvedimas į failus, taip pat visas programos vykdymo laikas
- Pakoreguota programos veikimo logika, dialogas su vartotoju

#### Programos veikimo greičio analizė (kuriami ir skaitomi įrašai su penkiais ND pažymiais)

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






















