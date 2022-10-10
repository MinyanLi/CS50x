-- Keep a log of any SQL queries you execute as you solve the mystery.

-- time: July 28, 2021
-- place: Humphrey Street

SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street ='Humphrey Street' AND description LIKE '%duck%';

-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time
-- each of their interview transcripts mentions the bakery.

SELECT name, transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%';

-- Ruth    Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
-- Eugene  I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- Raymond As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.


-- earliest flight
CREATE TABLE earliest_flight_tomorrow AS
    SELECT *
    FROM flights
    WHERE origin_airport_id = (
            -- find Fiftyville airport id
            SELECT id
            FROM airports
            WHERE city = 'Fiftyville')
        AND year = 2021 AND month = 7 AND day = 29
        ORDER BY hour, minute LIMIT 1;
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+

-- find destination
SELECT city FROM airports WHERE id = 4;
-- New York City


-- passengers on the earliest flight
CREATE TABLE earliest_flight_passengers AS
    SELECT *
      FROM people
     WHERE passport_number IN (
        -- find passenger passport number
        SELECT passport_number
        FROM passengers
        WHERE flight_id = (
            SELECT id
            FROM earliest_flight_tomorrow));


-- license plate exit bakery on July 28, 2021
CREATE TABLE exit_bakery AS
        SELECT *
        FROM bakery_security_logs
        WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25 AND activity = 'exit';

-- person exit bakery on July 28, 2021
CREATE TABLE person_exit_bakery AS
    SELECT *
    FROM people
    WHERE license_plate IN (SELECT license_plate FROM exit_bakery);


-- match passengers on the earliest flight with person exit bakery on July 28, 2021
CREATE TABLE passenger_exit_bakery AS
    SELECT *
    FROM person_exit_bakery
    WHERE id IN (
        SELECT id
        FROM earliest_flight_passengers);


-- find out person withdraw money from ATM on that day
CREATE TABLE person_withdraw_money AS
    SELECT person_id
    FROM bank_accounts
    WHERE bank_accounts.account_number IN (
        -- find out account number withdraw money from ATM on that day
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2021 AND month = 7 AND day = 28
            AND atm_location = 'Leggett Street'
            AND transaction_type = 'withdraw');

-- match person withdraw money with passengers on the earliest flight and exit bakery on the day
CREATE TABLE atm_bakery_passenger AS
    SELECT *
    FROM passenger_exit_bakery
    WHERE id IN (
        SELECT *
        FROM person_withdraw_money);

-- +--------+--------+----------------+-----------------+---------------+
-- |   id   |  name  |  phone_number  | passport_number | license_plate |
-- +--------+--------+----------------+-----------------+---------------+
-- | 467400 | Luca   | (389) 555-5198 | 8496433585      | 4328GD8       |
-- | 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       |
-- +--------+--------+----------------+-----------------+---------------+

-- candidate's phone call history
CREATE TABLE suspect_call AS
    SELECT *
    FROM phone_calls
    WHERE caller IN (
            SELECT phone_number
            FROM atm_bakery_passenger)
        AND year = 2021 AND month = 7 AND day = 28
        AND duration <= 60;

-- +-----+----------------+----------------+------+-------+-----+----------+
-- | id  |     caller     |    receiver    | year | month | day | duration |
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       |
-- +-----+----------------+----------------+------+-------+-----+----------+

-- receiver phone (375) 555-8161
SELECT name FROM people WHERE phone_number = '(375) 555-8161';
