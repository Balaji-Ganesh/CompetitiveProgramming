numPlaces, numRoutes = map(int, input().split())

routes = []
for i in range(numRoutes):
    routes.append(set(map(int, input().split()) ));        # placing as a set..

# Sort the routes based on the price(ASC)
routes = routes.sort(key=lambda x: x[2])
print(routes)


4 5
[(1, 2, 3), (1, 3, 5), (2, 3, 4), (3, 4, 1), (2, 4, 5)]